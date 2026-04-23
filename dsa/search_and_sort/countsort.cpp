

class Solution
{
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    public static String countSort(String arr)
    {
       String ans = "";
       int count[] = new int[50];
       for(int i = 0; i < arr.length(); i++){
           char ch = arr.charAt(i);
           int index = ch - 'a';
           count[index]++;
       }
       for(int i = 0; i < count.length; i++){
           while(count[i]>=1){
               ans += (char)(i+'a');
               count[i]--;
           }
       }
       return ans;
    }
}