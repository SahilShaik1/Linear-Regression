#include <iostream>
#include <vector>

using namespace std;

vector<int> fillX(int sVal, int eVal){
    vector<int> vals;
    for(int i = sVal; i < eVal; i++){
        vals.push_back(i);
    }
    return vals;
}

vector<double> fillY(double m, double b, vector<int> X_vals){
    //Y = MX + B
    vector<double> vals;
    for(int i = 0; i < X_vals.size(); i++){
        vals.push_back((X_vals[i] * m) + b);
    }
    return vals;
}


int main() 
{
    //Training x and y values
    vector<int> trainX = fillX(0, 100);
    vector<double> trainY = fillY(-5, 7, trainX);
    //size of vectors
    int size = trainX.size();
    cout << "training size: " << size << "\n";
    //Viewing the Error Rate over each Epoch/Training Set
    vector<double> error;
    //stores the error value
    double error_val;
    //a + bx
    double a, b = 0;
    //The amount each training set will be run through
    int repeatRate = 40;
    //Rate of change
    double learnRate = .01;

    for(int i = 0; i < size * repeatRate; i++){
        //to get an index value always between 0 - 4
        int index = i % 5;
        //Predicted value based on current a and b
        double pred = a + b * trainX[index];
        //Error value / Residual
        error_val = pred - trainY[index];
        //get the new a and b val
        a = a - learnRate * error_val;
        b = b - learnRate * error_val * trainX[index];
        //To get the error val for each set
        error.push_back(error_val);        
    }

    for(int i = 0; i < error.size(); i++){
        cout << "Error Rate " << i << " Epoch: " << error[i] << "\n";
    }
    double testingVal;
    cin >> testingVal;
    double pred = a + b*testingVal;
    cout << "Predicted Val: " << pred << "\n";
    cout << "a: " << a << ", b = " << b;


    return 0;
}
