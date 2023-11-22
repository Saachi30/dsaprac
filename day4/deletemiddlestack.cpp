#include <bits/stdc++.h> 
void solve(stack<int>&inputStack, int mid, int index){
   if(index==mid){
      inputStack.pop();
      return;
   }
   int element=inputStack.top();
   inputStack.pop();
   solve(inputStack, mid, index+1);
   inputStack.push(element);
}
void deleteMiddle(stack<int>&inputStack, int N){
	int mid;
   // Write your code here
   if(N%2==0){
      mid=(N+1)/2;
   }
   else{
      mid=((N+1)/2)-1;
   }
   int index=0;
   solve(inputStack,mid,index);

   
}