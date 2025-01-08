#include <iostream>
#include <vector>
using namespace std;

void spiraltraverse(int rows, int cols,vector<vector<int>> nums){
    int top = 0;
    int bottom = rows-1;
    int left = 0;
    int right = cols-1;
    while(top<=bottom && left<=right){
        for(int j = left ; j <= right;j++){
            cout << nums[top][j] << " ";
        }
        top++;

        for(int j=top; j <= right;j++){
            cout << nums[j][right] << " ";
        }
        right--;

        for(int i = right;i>= left;i--){
            cout << nums[bottom][i] << " ";
        }
        bottom--;
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << nums[i][left] << " ";
            }
            left++;
        }
    }

}
int main()
{
    vector<vector<int>> nums;
    int n, m, k;
    cout << "enter number of rows \n";
    cin >> m;
    cout << "enter number of columns" ;
    cin >> m;
    nums.resize(n, vector<int>(m));
    cout << "Enter matrix elements row by row:\n" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >>  nums[i][j];
            }
    }
    spiraltraverse(n,m,nums);
    }