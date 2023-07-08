void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{

    /*
    ->So this question is based more on observation and when we look closely this question look similar
        to spiral matrix implementation just one idea to keep in mind is that we should run the loop 
        whenever left boundary is less than right boundary and top boundary is less than bottom 
        boundary 
    ->TC - O(max(n,m)) SC- O(1)
    */
    int top = 0, left = 0, bottom = n-1, right = m-1;
    while(top < bottom && left < right){
        int temp = mat[top][left];
        int row = top, col = left;
        for(int i = left+1; i<=right; i++){
            swap(mat[top][i],temp);
        }
        top++;
        for(int i = top; i<=bottom; i++){
            swap(mat[i][right],temp);
        }
        right--;
        if(top <= bottom){
            for(int i = right; i>=left; i--){
                swap(mat[bottom][i],temp);
            }
        }
        bottom--;
        if(left <= right){
            for(int i = bottom; i>=top; i--){
                swap(mat[i][left],temp);
            }
        }
        left++;
        swap(temp,mat[row][col]);
    }
}