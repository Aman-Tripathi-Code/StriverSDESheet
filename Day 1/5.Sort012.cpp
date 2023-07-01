void sort012(int *arr, int n)
{
   /*
   ->We can use normal sorting function
   ->TC - O(Nlog(N))

   -> We can use a frequency array or three variable and store the frequency of 0,1 and 2 
   -> For the frequency of 0 put the number of 0 in the array first then for the frequency of 1 put
      the number of 1 and so on
   -> TC - O(N) SC - O(1)

   -> To solve the problem in one scan we can use Dutch flag algorithm 
   -> In this we will take three variable lo, mid and hi
   -> The idea is to put all 0 in lo to mid 1 in mid to hi and 2 in hi range 
   -> We will set lo and mid as 0 and hi as size-1
   -> It is observe that array from lo to mid is already sorted so we have to sort until mid to hi
   -> If the element is 0 we swap it with lo or if it is 2 we swap it with hi this make sure the
      array is sorted in range lo to mid-1 and hi to size - 1
   -> TC - O(N) SC - O(1)
   */

   int lo = 0, mid = 0, hi = n-1;

   while(mid<=hi){
      if(arr[mid] == 0){
         swap(arr[lo],arr[mid]);
         lo++;
         mid++;
      }
      else if(arr[mid] == 1){
         mid++;
      }
      else{
         swap(arr[mid],arr[hi]);
         hi--;
      }

   }
}