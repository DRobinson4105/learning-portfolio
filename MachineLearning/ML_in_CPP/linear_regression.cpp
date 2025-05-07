#include <iostream>
#include <cstdlib>

using namespace std;

double mse(vector<double> y_true, vector<double> y_pred) {
    if (y_true.size() != y_pred.size()) {
        throw;
    }
    double sum = 0;
    int n = y_true.size();

    for (int i = 0; i < n; i++) {
        sum += pow(fabs(y_true[i] - y_pred[i]), 2);
    }
    
    return sum / y_true.size();
}

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
};

class Neuron {
public:
    double weight, bias;

    Neuron() {
        weight = bias = 0;
    }

    Neuron(int lo, int hi) {
        weight = (double)rand() / RAND_MAX * (hi-lo) + lo;
        bias = (double)rand() / RAND_MAX * (hi-lo) + lo;
    }

    vector<double> operator()(vector<double> input) {
        vector<double> prediction(input.size());
        transform(input.begin(), input.end(), prediction.begin(), [this](int x) {
            return x * weight + bias;
        });
        return prediction;
    }
};

class Optimizer {
public:
    int patience, epochs;
    double lr, factor;
    Neuron& model;
    Dataset dataset;

    Optimizer(Neuron& model, Dataset dataset, double lr, double factor, int patience):
        model(model), dataset(dataset), lr(lr), factor(factor), patience(patience), epochs(0) {}

    void step() {
        double best_weight = 0, best_bias = 0, best_loss = pow(2, 1023);
        double starting_weight = model.weight, starting_bias = model.bias;
        double starting_loss = mse(dataset.output, model(dataset.input));

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                model.weight = starting_weight + i * lr;
                model.bias = starting_bias + j * lr;
                double cur_loss = mse(dataset.output, model(dataset.input));
                if (cur_loss < best_loss) {
                    best_loss = cur_loss;
                    best_weight = model.weight + i * cur_loss * lr;
                    best_bias = model.bias + j * cur_loss * lr;
                }
            }
        }

        model.weight = best_weight;
        model.bias = best_bias;

        if (starting_loss == best_loss) {
            epochs++;
        }

        if (epochs >= patience) {
            epochs = 0;
            lr *= factor;
        }
    }
};

int main() {
    srand(56);

    Dataset data(0, 10, 3, 1);

    int epochs = 10000;
    double lr = 1e-3;
    double factor = 0.9;
    int patience = 10;

    Neuron model(-pow(2, 1027), pow(2, 1027));
    Optimizer optim(model, data, lr, factor, patience);
    
    cout << model.weight << " " << model.bias << endl;
    cout << mse(data.output, model(data.input)) << endl;

    for (int i = 0; i < epochs; i++) {
        optim.step();
    }

    cout << model.weight << " " << model.bias << endl;
    cout << mse(data.output, model(data.input)) << endl;
    
    return 0;
}