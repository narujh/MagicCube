#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void vector_print (vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void vector_print (vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

// int formingMagicSquare(vector<vector<int>> v)
// {
//     int best = 100;
//     vector<int> t;
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             t.push_back(v[i][j]);
//         }
//     }

// }

int formingMagicSquare(vector<vector<int>> s)
{
    vector<int> check {8, 3, 4, 9, 2, 7, 6, 1};

    int result = 100; 

    for (int k = 0; k < check.size(); k++)
    {
        int a = 1;
        int i = 0;
        int j = 0;
        int sum = 0;

        for (int l = 0; l < check.size(); l++)
        {
            if ((k % 2) == 0)
            {
                sum = sum + abs(s[i][j] - check[l]);
            }
            else
            {
                sum = sum + abs(s[i][j] - check[check.size()-l-1]);
            }

            if ((i == j) && (j == 2))
            {
                a = -a;
            }

            if (((a < 0) && (j != 0)) || ((j != 2) && (a > 0)))
            {
                j = j + a;
            }
            else
            {
                i = i + a;
            }    
        }

        sum = sum + abs(s[1][1] - 5);

        if (sum < result)
        {
            result = sum;
        }

        int t = *(check.end()-1);
        check.pop_back();
        check.insert(check.begin(), t);
    }
    return result;
}

int main()
{
    vector<vector<int>> input {{7, 2, 9}, {6, 6, 2}, {5, 1, 2}};
     cout << "\n" << formingMagicSquare(input);
    
    return 0;
}

/*
1 3 8
6 4 1
2 6 5
Expected Output

Download
9

7 2 9
6 6 2
5 1 2
Expected Output

Download
19
*/ 
