#include <iostream>
#include <cstdlib>
#include <numeric>
#include <execution>
#include <random>

typedef std::function<std::unordered_map<std::string, double>(std::vector<double>, std::vector<double>)> gradient_function_t;

class Tensor {
    public:
        std::vector<double> value;
        Model* source;
        gradient_function_t gradient_function;
    
        Tensor(): value(std::vector<double>()), source(nullptr), gradient_function(nullptr) {}
    
        Tensor(std::vector<double> value): value(value), source(nullptr), gradient_function(nullptr) {}
        
        Tensor(std::vector<double> value, Model* source, gradient_function_t gradient_function):
            value(value), source(source), gradient_function(gradient_function) {}
    };
    
    class Dataset {
        std::vector<double> _input;
        std::vector<double> _output;
    public:
        Dataset() {}
        Dataset(int start, int stop, double w, double b);
        const std::pair<double, double> operator[](int index);
        int size();
        std::vector<double> input();
        std::vector<double> output();
    };
    
    class Model {
        std::unordered_map<std::string, double> _parameters;
        std::unordered_map<std::string, double> _gradients;

    public:
        Model();
        Tensor operator()(std::vector<double> input);
        void setGradients(std::unordered_map<std::string, double> gradients);
        std::unordered_map<std::string, double> parameters();
        std::unordered_map<std::string, double> gradients();
    };
    
    class MSELoss {
    public:
        double operator()(Tensor y_pred, std::vector<double> y_true);
    };
    
    class Optimizer {
        int patience, epochs;
        double lr, factor, best_loss;
        Model& model;
        Dataset dataset;
    
    public:
        Optimizer(Model& model, Dataset dataset, double lr, double factor, int patience);
        void step(double loss);
    };
    
    void printMap(std::unordered_map<std::string, double> m);