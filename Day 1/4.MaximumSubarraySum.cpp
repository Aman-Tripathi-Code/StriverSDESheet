long long maxSubarraySum(int arr[], int n)
{
    /*
    -> First approach is to run three nested loops and find the sum of subarray for each element
    -> Then take maximum of them
    -> TC - O(N*N*N) SC - O(1)

    ->Second approach is to run two nested loops but in this we will compare the sum of subarray at
        every subarray
    -> TC - O(N*N) SC - O(1)

    ->In this approach we will just run a loop once a maintain two variable sum and maxi
    ->If we get a positive sum we will just move to next iteration comparing it to maxi
    ->But if we get a negative sum we will compare it with maxi and reset to 0 as we do not want 
        a smaller sum in case the next element are also negative
    -> TC - O(N) SC - O(1)
    */


    long long sum = 0, maxi = -1e9;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        maxi = max(maxi,sum);
        if(sum < 0) sum = 0;
    }
    return (maxi < 0) ? 0 : maxi;
}