#~/Code/Experiment_Framework/tests/test_experiment.py

#Core Imports
import sys
import os
import unittest
import argparse

#Library Imports

#User File Imports

sys.path.insert(1, os.getcwd()+"/../experiment")

from experiment import Experiment

#Global Constants:

#Global Variables:

#Test Cases

class TestExperiment(unittest.TestCase):
    def setUp(self) -> None:
        self.test_experiment = Experiment(name="test_experiment",
                                          algorithm="test_algorithm")
        return super().setUp()
    
    def tearDown(self) -> None:
        return super().tearDown()
    
    #Object Creation
    def test_experiment_exists(self):
        self.assertTrue(self.test_experiment)

    #Name
    def test_experiment_name(self):
        self.assertEqual(self.test_experiment.get_name(), "test_experiment")

    def test_experiment_set_name(self):
        self.test_experiment.set_name(name="test_experiment_2")
        self.assertEqual(self.test_experiment.get_name(),"test_experiment_2")

    #Algorithm
    def test_expriment_algorithm(self):
        self.assertEqual(self.test_experiment.get_algorithm(), "test_algorithm")

    def test_experiment_set_algorithm(self):
        self.test_experiment.set_algorithm(algorithm="test_algorithm_2")
        self.assertEqual(self.test_experiment.get_algorithm(),"test_algorithm_2")

    #Number of Workers (Serial or Parallel)
    def test_experiment_num_workers(self):
        self.assertEqual(self.test_experiment.get_num_workers(), 1)

    def test_experiment_set_num_workers(self):
        self.test_experiment.set_num_workers(num_workers=2)
        self.assertEqual(self.test_experiment.get_num_workers(), 2)

    def test_get_operating_system(self):
        self.assertIsNotNone(self.test_experiment.get_os_detail())

    #Timing
    def test_get_timing_dict(self):
        test_timing_dict = {"experiment_created": None,
                            "experiment_start":None,
                            "metadata_dumped":None,
                            "etl_start":None,
                            "etl_end":None,
                            "test_start":None,
                            "test_end":None,
                            "results_dumped":None,
                            "experiment_end":None}
        self.assertListEqual(list(self.test_experiment.get_timings().keys()), list(test_timing_dict.keys()))

    #Results

    def test_experiment_data_directory(self):
        expected_directory= os.path.join(os.getcwd(), "..", "..","..","Experiment_Results")
        self.assertEqual(self.test_experiment.get_data_directory(), expected_directory)

    def test_experiment_results_directory_creation(self):
        results_directory = os.path.join(os.getcwd(),"..","..","..","Experiment_Results")
        experiment_results_directory = os.path.join(results_directory,"test_experiment")
        self.test_experiment.dump_experiment_metadata()
        self.assertTrue(os.path.isdir(results_directory))



    #Data
    def test_experiment_data_directory(self):
        expected_directory= os.path.join(os.getcwd(), "..", "..","..","Data")
        self.assertEqual(self.test_experiment.get_data_directory(), expected_directory)

    def test_experiment_data_directory_exists(self):
        expected_directory= os.path.join(os.getcwd(), "..", "..","..","Data")
        self.assertTrue(os.path.isdir(self.test_experiment.get_data_directory()))

    def test_experiment_set_data_directory(self):
        new_directory = os.path.join(os.getcwd(), "..", "..","..","Data","test_data")
        self.test_experiment.set_data_directory(data_directory=new_directory)
        self.assertEqual(self.test_experiment.get_data_directory(), new_directory)

    def test_experiment_load_data_file(self):
        file_path = os.path.join(os.getcwd(), "..", "..","..","Data","test_data","test_adjacency_list.txt")
        self.assertTrue(os.path.isfile(file_path))

    def test_get_graph_properties(self):
        file_path = os.path.join(os.getcwd(), "..", "..","..","Data","test_data","test_adjacency_list.txt")

        expectedGraph = {"node_count":3,
                         "edge_count":3,
                         "mean_degree":2.0,
                         "bytes_on_disk":11,
                         "bytes_in_memory":56}
        
        self.test_experiment.load_graph(graph_file=file_path)

        self.assertDictEqual(self.test_experiment.get_graph_summary(),expectedGraph)

    


#Main Function
if __name__=='__main__':

    unittest.main()