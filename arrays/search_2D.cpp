    #include <stdio.h>
    #include <vector>
    using namespace std;

    bool search(int rows, int cols, int key, vector<vector<int>> nums)
    {
        int mid;
        for (int i = 0; i < rows; i++)
        {
            if (nums[i][0] <= key && nums[i][cols - 1] >= key)
            {
                int low = 0;
                int high = cols - 1;
                while (low <= high)
                {
                    int mid = (high+low) / 2;
                    if (nums[i][mid] == key)
                    {
                        return true;
                    }
                    else if (nums[i][mid] < key)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
        }
        return false;
    }
    int main()
    {
        vector<vector<int>> nums;
        int n, m, k;
        printf("enter number of rows \n");
        scanf("%d", &n);
        printf("enter number of columns");
        scanf("%d", &m);
        nums.resize(n, vector<int>(m));
        printf("Enter matrix elements row by row:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &nums[i][j]);
            }
        }

        printf("Enter the key element to search: ");
        scanf("%d", &k);

        bool found = search(n, m, k, nums);
        if (found)
        {
            printf("Key found in the matrix.\n");
        }
        else
        {
            printf("Key not found in the matrix.\n");
        }

        return 0;
    }