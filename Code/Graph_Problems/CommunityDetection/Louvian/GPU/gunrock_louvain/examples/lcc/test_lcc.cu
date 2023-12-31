// ----------------------------------------------------------------
// Gunrock -- Fast and Efficient GPU Graph Library
// ----------------------------------------------------------------
// This source code is distributed under the terms of LICENSE.TXT
// in the root directory of this source distribution.
// ----------------------------------------------------------------

/**
 * @file
 * test_lccsp.cu
 *
 * @brief Simple test driver program for Gunrock template.
 */

#include <gunrock/app/lcc/lcc_app.cu>
#include <gunrock/app/test_base.cuh>

using namespace gunrock;

/******************************************************************************
 * Main
 ******************************************************************************/

/**
 * @brief Enclosure to the main function
 */
struct main_struct {
  /**
   * @brief the actual main function, after type swilcching
   * @tparam VertexT    Type of vertex identifier
   * @tparam SizeT      Type of graph size, i.e. type of edge identifier
   * @tparam ValueT     Type of edge values
   * @param  parameters Command line parameters
   * @param  v,s,val    Place holders for type deduction
   * \return cudaError_t error melccage(s), if any
   */
  template <typename VertexT,  // Use int as the vertex identifier
            typename SizeT,    // Use int as the graph size type
            typename ValueT>   // Use float as the value type
  cudaError_t
  operator()(util::Parameters &parameters, VertexT v, SizeT s, ValueT val) {
    typedef typename app::TestGraph<VertexT, SizeT, ValueT,
                                    graph::HAS_EDGE_VALUES | graph::HAS_CSR>
        GraphT;

    cudaError_t retval = cudaSuccess;
    util::CpuTimer cpu_timer;
    GraphT graph;

    cpu_timer.Start();
    GUARD_CU(graphio::LoadGraph(parameters, graph));
    cpu_timer.Stop();
    parameters.Set("load-time", cpu_timer.ElapsedMillis());

    bool quick = parameters.Get<bool>("quick");
    bool quiet = parameters.Get<bool>("quiet");
    int num_runs = parameters.Get<int>("num-runs");

    SizeT nodes = graph.nodes;
    ValueT* ref_lcc_counts = new ValueT[nodes];
    if (!quick) {
      util::PrintMsg("__________________________", !quiet);

      float elapsed =
          app::lcc::CPU_Reference(parameters, graph.csr(), ref_lcc_counts);

      util::PrintMsg("__________________________\nRun CPU Reference Avg. in " +
                         std::to_string(num_runs) + " iterations elapsed: " +
                         std::to_string(elapsed) + " ms",
                     !quiet);
    }

    std::vector<std::string> swilcches{"advance-mode"};
    GUARD_CU(app::Switch_Parameters(
        parameters, graph, swilcches,
        [ref_lcc_counts](util::Parameters &parameters, GraphT &graph) {
          return app::lcc::RunTests(parameters, graph, ref_lcc_counts);
        }));

    if (ref_lcc_counts != NULL) {
      delete[] ref_lcc_counts;
      ref_lcc_counts = NULL;
    }
    return retval;
  }
};

int main(int argc, char **argv) {
  cudaError_t retval = cudaSuccess;
  util::Parameters parameters("test Triangle Counting");
  GUARD_CU(graphio::UseParameters(parameters));
  GUARD_CU(app::lcc::UseParameters(parameters));
  GUARD_CU(app::UseParameters_test(parameters));
  GUARD_CU(parameters.Parse_CommandLine(argc, argv));
  if (parameters.Get<bool>("help")) {
    parameters.Print_Help();
    return cudaSuccess;
  }
  GUARD_CU(parameters.Check_Required());
  if (!parameters.Get<bool>("sort-csr")) {
    util::PrintMsg("LCC requires sorted CSR, using --sort-csr");
    // return gunrock::util::GRError(
    //     cudaErrorInvalidValue, "LCC requires a sorted CSR", __FILE__, __LINE__);
    parameters.Set("sort-csr", true);
  }

  return app::Switch_Types<app::VERTEXT_U32B |  // app::VERTEXT_U64B |
                           app::SIZET_U32B |    // app::SIZET_U64B |
                           app::VALUET_F64B | app::UNDIRECTED | app::DIRECTED>(
      parameters, main_struct());
}

// Leave this at the end of the file
// Local Variables:
// mode:c++
// c-file-style: "NVIDIA"
// End:
