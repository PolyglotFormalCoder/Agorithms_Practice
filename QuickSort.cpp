#include <iostream>
#include <memory>
#include <vector>
using namespace std;

void swap(int* Input, int x, int y)
{
    int temp = Input[x];
    Input[x] = Input[y];
    Input[y] = temp;
}

int Parition(int* Input, int start, int end)
{
    int Pivot = end;
    int PIndex = start;
    int j = PIndex;  
        std::cout<<std::endl;
    for (int index=start; index < Pivot; index++  )
    {
        if (Input[index]< Input[Pivot])
        {
            swap(Input, index, j);
            j++;
            PIndex++;
            
        }        
    }
    
    swap(Input, PIndex,  Pivot);
    std::cout<<"pivot value: "<<PIndex<<" "<<Pivot<<std::endl;
    std::cout<<"partition end"<<std::endl;
            for (int i = 0; i < 6; i++)
        std::cout<<Input[i]<<"  ";
        std::cout<<std::endl; 
    return PIndex;
}

void QuickSort(int *Input, int left, int right)
{
   if(left < right)
   {
       int PIndex = Parition(Input, left, right);
       QuickSort(Input, left, PIndex-1);
       QuickSort(Input, PIndex+1, right);
   }

}
int main()
{
    int input[] = {9,8,888,999,99,0};
    QuickSort(input, 0, 5);
    std::cout<<"final value"<<std::endl;
    for (int i = 0; i < 6; i++)
        std::cout<<input[i]<<"  ";
    std::cout<<std::endl;
}
