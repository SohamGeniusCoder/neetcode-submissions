class Solution 
{
public:
    int binarySearchRow(vector<vector<int>> &matrix,int target,int rows,int row_top,int row_bottom,int cols)
    {
        int mid = (row_top+row_bottom)/2;
        if(row_top>row_bottom)
        {
            return -1;
        }
        else if(target >= matrix[mid][0] && target <= matrix[mid][cols-1])
        {
            return mid;
        }
        else if(target<matrix[mid][0])
        {
            return binarySearchRow(matrix,target,rows,row_top,mid-1,cols);
        }
        else if(target>matrix[mid][cols-1])
        {
            return binarySearchRow(matrix,target,rows,mid+1,row_bottom,cols);
        }
        return -1;
    }
    bool binarySearch(vector<vector<int>>& matrix,int target,int row,int left,int right)
    {
        while(left<=right)
        {
                int mid=(left+right)/2;

                if(matrix[row][mid]==target)
                {
                     return true;
                }
                

                if(matrix[row][mid]<target)
                {
                        left=mid+1;
                }
                
                else
                {
                        right=mid-1;
                }
                
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int cols = matrix[0].size();int rows = matrix.size();
        int col_mid = cols/2;int row_mid = rows/2;

        int row = binarySearchRow(matrix,target,rows,0,rows-1,cols);
        if(row == -1)
        {
                return false;
        }
        bool col = binarySearch(matrix,target,row,0,cols-1);
        if(!col)
        {
                return false;
        }
        return true;


    }
};
