#include <iostream>
#include <cstdlib>
#include <numeric>
#include <execution>

using namespace std;

typedef function<unordered_map<string, double>(vector<double>, vector<double>)> gradient_function_t;

class Model;
class Tensor;
class MSELoss;
class Optimizer;
void printMap(unordered_map<string, double> m);

class Tensor {
public:
    vector<double> value;
    Model* source;
    gradient_function_t gradient_function;

    Tensor(): value(vector<double>()), source(nullptr), gradient_function(NULL) {}

    // Tensor(vector<double> value): value(value), source(nullptr), gradient_function(NULL) {}
    
    Tensor(vector<double> value, Model* source, gradient_function_t gradient_function):
        value(value), source(source), gradient_function(gradient_function) {}
};

class Dataset {
public:
    vector<double> input;
    vector<double> output;

    Dataset() {}

    Dataset(int start, int stop, double w, double b) {
        if (start < 0 || start > stop) {
            throw;
        }
    
        int n = stop - start;

        input = vector<double>(n);
        output = vector<double>(n);

        for (int i = 0; i < n; i++) {
            input[i] = i+start;
            output[i] = (i+start) * w + b;
        }
    }

    const pair<double, double> operator[](int index) {
        return {input[index], output[index]};
    }

    int size() {
        return input.size();
    }
};

class Model {
public:
    unordered_map<string, double> parameters;
    unordered_map<string, double> gradients;

    Model() {
        parameters["weight"] = (double)rand() / RAND_MAX;
        parameters["bias"] = (double)rand() / RAND_MAX;
    }

    Tensor operator()(vector<double> input) {
        vector<double> prediction(input.size());
        transform(input.begin(), input.end(), prediction.begin(), [this](double x) {
            return x * parameters["weight"] + parameters["bias"];
        });

        // for (int i = 0; i < input.size(); i++) {
        //     cout << input[i] << " " << prediction[i] << endl;
        // }

        return Tensor(prediction, this, [input](vector<double> y_pred, vector<double> y_true) {
            unordered_map<string, double> grad;

            // for (int i = 0; i < y_pred.size(); i++) {
            //     cout << y_pred[i] << " " << y_true[i] << endl;
            // }
        
            transform(y_pred.begin(), y_pred.end(), y_true.begin(), y_true.begin(), minus<>());

            grad["bias"] = accumulate(y_true.begin(), y_true.end(), 0.0);
            grad["weight"] = inner_product(y_true.begin(), y_true.end(), input.begin(), 0.0);

            // printMap(grad);

            // for (int i = 0; i < y_true.size(); i++) {
            //     cout << y_true[i] << endl;
            // }
            // cout << endl;
            // cout << grad["bias"] << " " << grad["weight"] << endl;
            grad["bias"] *= 2.0 / input.size();
            grad["weight"] *= 2.0 / input.size();

            return grad;
        });
    }
};

class MSELoss {
public:
    double operator()(Tensor y_pred, vector<double> y_true) {
        // for (int i = 0; i < y_pred.value.size(); i++) {
        //     cout << y_pred.value[i] << " " << y_true[i] << endl;
        // }
        y_pred.source->gradients = y_pred.gradient_function(y_pred.value, y_true);
        transform(y_pred.value.begin(), y_pred.value.end(), y_true.begin(), y_true.begin(), [](double a, double b) {
            return pow(a - b, 2);
        });

        // for (double val : y_true) {
        //     cout << val << endl;
        // }

        return accumulate(y_true.begin(), y_true.end(), 0.0) / y_pred.value.size();
    }
};

class Optimizer {
    int patience, epochs;
    double lr, factor, best_loss;
    Model& model;
    Dataset dataset;

public:
    Optimizer(Model& model, Dataset dataset, double lr, double factor, int patience):
        model(model), dataset(dataset), lr(lr), factor(factor), patience(patience), epochs(0), best_loss(pow(2, 1027)) {}

    void step(double loss) {
        unordered_map<string, double> grad = model.gradients;

        for (auto [k, v] : grad) {
            model.parameters[k] -= lr * v;
        }

        // cout << best_loss << " " << epochs << " " << patience << " " << loss << " " << lr << endl;
        if (loss < best_loss) {
            best_loss = loss;
            epochs = 0;
        } else if (loss == best_loss) {
            epochs++;
        }
        
        if (epochs >= patience) {
            lr *= factor;
            epochs = 0;
        }
    }
};

void printMap(unordered_map<string, double> m) {
    for (auto [k, v] : m) {
        printf("[\"%s\"]=%lf\n", k.c_str(), v);
    }
}

int main() {
    srand(56);

    Dataset data(0, 10, 3, 1);

    // for (double d : data.output) {
    //     cout << d << endl;
    // }

    int epochs = 10000;
    double lr = 1e-3;
    double factor = 1;
    int patience = 10;

    Model model;
    Optimizer optim(model, data, lr, factor, patience);
    MSELoss criterion;

    Tensor y_pred;
    double loss;
    
    printf("Before Training:\n");
    printf("Parameters\n");
    printMap(model.parameters);
    y_pred = model(data.input);
    loss = criterion(y_pred, data.output);
    printf("Gradients\n");
    printMap(model.gradients);
    printf("Loss: %lf\n\n", loss);

    for (int i = 0; i < epochs; i++) {
        y_pred = model(data.input);
        loss = criterion(y_pred, data.output);
        optim.step(loss);
    }

    printf("After Training:\n");
    printf("Parameters\n");
    printMap(model.parameters);
    y_pred = model(data.input);
    loss = criterion(y_pred, data.output);
    printf("Gradients\n");
    printMap(model.gradients);
    printf("Loss: %lf\n", loss);

    return 0;
}