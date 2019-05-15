#include "search.h"

int seqsearch(int a[],int key)
{
      int i;

      for(i = N-1; i >= 0; i--)
	    if(key == a[i])
		  return i;   //查找成功，返回i
      return -1;  // 查找失败，返回-1
}
