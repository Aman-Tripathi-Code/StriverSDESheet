vector<int> nextPermutation(vector<int> &permutation, int n)
{
    /*
    -> We will sort the array.
    -> We can find all the permutation of the array using recursion and store it in the data structure
    -> Now we will iterate over data structure and return the ans 
    -> TC - O(N!*N) SC - O(N!*N) 

    -> We can use the next_permutation stl function to find the next permutation 
    -> Syntax next_permutation(v.begin(),v.end());
    -> In case if the next_permutation is false we have to return the reverse of the original array
    -> TC - O(N) SC - O(1)
    

    -> We can observe that in the given array the value will increase for some time then decrease
    -> Now we can check from the end of the array for the pivot element because after the pivot element the
        permutation is at its maximum 
    -> So we will find the index of element for which its next element its greater than itself
    -> If the index comes out to be -1 we will just reverse the array and retrun it
    -> Now we will find the index of the element will is greater than the index1 element and swap them
    -> After swapping we will reverse the array after index1 as to get the minimum next permutation
    -> TC - O(N) SC - O(1)
    */

    int ind1 = -1;
    for(int i = n-2; i>=0; i--){
        if(permutation[i] < permutation[i+1]){
            ind1 = i;
            break;
        }
    }  

    if(ind1 == -1){
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }
    int ind2 = -1;

    for(int i = n-1; i>ind1; i--){
        if(permutation[i] > permutation[ind1]){
            ind2 = i;
            break;
        }
    }
    swap(permutation[ind1],permutation[ind2]);
    reverse(permutation.begin()+ind1+1,permutation.end());

    return permutation;
}