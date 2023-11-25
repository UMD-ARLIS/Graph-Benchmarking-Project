from generate_CD_problems import LFR_generator

experiment_000 = {"dataset_number":"000",
                 "n":1000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.05,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_001 = {"dataset_number":"001",
                 "n":1000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.10,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_002 = {"dataset_number":"002",
                 "n":1000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.25,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_003 = {"dataset_number":"003",
                 "n":1000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.50,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_004 = {"dataset_number":"004",
                 "n":1000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.75,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_005 = {"dataset_number":"005",
                 "n":1000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.99,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }


experiment_006 = {"dataset_number":"006",
                 "n":1000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.05,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_007 = {"dataset_number":"007",
                 "n":10000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.10,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_008 = {"dataset_number":"008",
                 "n":10000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.25,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_009 = {"dataset_number":"009",
                 "n":10000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.50,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_010 = {"dataset_number":"010",
                 "n":10000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.75,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiment_011 = {"dataset_number":"011",
                 "n":10000,
                 "tau1":3.00,
                 "tau2":1.50,
                 "mu":0.99,
                 "k":10.0,
                 "min_community":200,
                 "seed":10
                 }

experiments = [experiment_000,
                experiment_001, 
                experiment_002, 
                experiment_003,
                experiment_004,
                experiment_005,
                experiment_006,
                experiment_007,
                experiment_008,
                experiment_009,
                experiment_010,
                experiment_011,                
                ]

if __name__ == "__main__":
    for exp in experiments:
        print("Generating Dataset #{num}".format(num=exp["dataset_number"]))
        LFRG = LFR_generator(n=exp["n"], 
                            tau1=exp["tau1"], 
                            tau2=exp["tau2"], 
                            mu=exp["mu"], 
                            k=exp["k"], 
                            min_community=exp["min_community"], 
                            seed=exp["seed"],
                            dataset_number=exp["dataset_number"]
                            )
        LFRG.generate_dataset()