#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <fstream>
#include <unistd.h>
using namespace std;

int Example(vector<int> X)
{
    int y = 0;

    for (int i = 0; i < X.size(); i++)
    {
        if (X[i] == 0)
        {
            for (int j = i; j < X.size(); j++)
            {
                for (int k = X.size(); k >= 1; k = k / 2)
                {
                    y++;
                }
            }
        }
        else
        {
            for (int m = i; m < X.size(); m++)
            {
                y++;
            }
        }
    }

    return y;
}
vector<int> generateRandomimput(int size)
{
    vector<int> X_avarage_case;
    for (int i = 0; i < size; i++)
    {
        int RandIndex = rand() % 2;
        X_avarage_case.push_back(RandIndex);
    }
    return X_avarage_case;
}

int main()
{
    vector<int> resultofbestcases;
    vector<int> resultofworstcases;
    vector<int> resultofaveragecases;
    srand(time(NULL));
    int size = 0;
    for (int index = 0; index < 20; index++)
    {
        size = size + 50;
        vector<int> X_best_case;
        vector<int> X_worst_case;
        vector<int> X_avarage_case;
        for (int i = 0; i < size; i++)
        {

            X_worst_case.push_back(0);
            X_best_case.push_back(1);
        }
        cout << " the list size is : " << size << endl;
        auto t1 = std::chrono::high_resolution_clock::now();
        Example(X_best_case);
        auto t2 = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        resultofbestcases.push_back(duration);
        std::cout << "Best case " << duration << endl;

        auto t3 = std::chrono::high_resolution_clock::now();
        Example(X_worst_case);
        auto t4 = std::chrono::high_resolution_clock::now();

        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
        resultofworstcases.push_back(duration2);
        std::cout << "Worst case " << duration2 << endl;

        auto duration3 = 0;
        for (int times = 0; times < 10; times++)
        {
            auto t5 = std::chrono::high_resolution_clock::now();
            Example(generateRandomimput(size));
            auto t6 = std::chrono::high_resolution_clock::now();

            duration3 += std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
        }

        resultofaveragecases.push_back(duration3 / 10);
        std::cout << "Average case " << duration3 / 10 << endl;
    }

    ofstream myfile;
    myfile.open("results.txt");
    int sx = resultofbestcases.size();

    for (int i = 0; i < sx; i++)
    {
        myfile << resultofbestcases[i] << " ";
    }
    myfile << "\n";
    for (int i = 0; i < sx; i++)
    {
        myfile << resultofworstcases[i] << " ";
    }
    myfile << "\n";
    for (int i = 0; i < sx; i++)
    {
        myfile << resultofaveragecases[i] << " ";
    }
    return 0;
}
