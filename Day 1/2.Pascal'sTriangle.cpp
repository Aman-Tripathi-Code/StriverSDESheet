vector<vector<long long int>> printPascal(int n) 
{
  // -> We can observe that a nth row can be represented as nC0 , nC1 , nC2 ....... nCn-1, nCn
  // -> So either we find the value of nCr and that will give our ans
  // -> But the value of n! factorial can be very big and modulo is also not given so we will not use this
  // -> Instead we can use the observation of nCr = n-1Cr + n-1Cr-1
  // -> TC - O(N * N) && SC = O(1) no extra space other than answer vector 

  vector<vector<long long int>> tri(n);
  for(int i = 0; i<n; i++){
    tri[i].resize(i+1);
    tri[i][0] = 1;
    for(int j = 1; j<i ; j++){
      tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
    }
    tri[i][i] = 1;
  }
  return tri;
}