#include "search.h"

int binsearch(int a[],int key)
{
      int low,high,mid;

      for(low = 0,high = N-1; low <= high;){
	    mid = (low + high) / 2;
	    if(key == a[mid])
		  return mid;   // 查找成功，返回mid
	    else if(key < a[mid]){
		  high = mid - 1;
	    }else
		  low = mid + 1;
      }
      return -1;  // 查找失败，返回-1
}
