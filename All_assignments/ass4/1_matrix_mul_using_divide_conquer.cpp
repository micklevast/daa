#include <iostream>
    // vector<int> result_matrix_row(col_2, 0);
    // vector<vector<int> > result_matrix(row_1,
    //                                    result_matrix_row);
#include <vector>
using namespace std;
void multiply(vector<vector<int>> &ans, vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    int mat1row = mat1.size();
    int mat1col = mat1[0].size();
    int mat2row = mat2.size();
    int mat2col = mat2[0].size();

    cout << mat1row << " " << mat1col << endl;
    cout << mat2row << " " << mat2col << endl;
    if (mat1col == mat2row)
    {
        for (int k = 0; k < mat1row; k++) // O(n^3)
        {
            for (int j = 0; j < mat2col; j++)
            {
                for (int i = 0; i < mat1col; i++)
                {

                    int mul = mat1[k][i] * mat2[i][j];
                    // cout<<"k:"<<k<<" "<<"j:"<<j<<"  i:"<<i<<endl;
                    cout << mul << " ";
                    ans[k][j] += mul;
                }
                cout << endl;
            }
        }
    }
    else
        cout << "matric multiplication is not possible as mat1row!=mat2col";
}
int main()
{
    vector<vector<int>> mat1{{1, 2, 1, 2},
                             {3, 2, 1, 1},
                             {2, 1, 1, 2},
                             {3, 1, 2, 1}};

    vector<vector<int>> mat2{{2, 1, 2, 1},
                             {2, 3, 2, 1},
                             {2, 2, 2, 1},
                             {1, 1, 2, 1}};
    vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size(), 0));
    cout << "ans row:" << ans.size() << " col:" << ans[0].size() << endl;

    multiply(ans, mat1, mat2);
    cout << "done\n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << "over\n";
}