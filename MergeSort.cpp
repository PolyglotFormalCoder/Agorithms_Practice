#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class MergeSort
{
public:
    MergeSort(std::vector<int> x):input(x){}
    void Sort(std::vector<int>& x, int left, int right)
    {       
       if(left<right)
       {
           
           int center = left+ (right-left)/2;
           
           //call recursively 
           Sort(input, left, center);
           Sort(input, center+1, right);          
           //merge
           //create 1st vector
           
           std::vector<int> Temp_vec1(input.begin() + left, input.begin() + center+1); 
                    
           //create 2nd vector
           std::vector<int> Temp_vec2(input.begin() + center+1, input.begin() + right+1);
           std::cout<<"entering sort. "<<"left: "<<left<<" right: "<<right<<std::endl;
           std::cout <<"center: "<<center<<std::endl;
          std::cout<<"left:"<<std::endl;
           for(int ind=0; ind<Temp_vec1.size();ind++)
                std::cout<<Temp_vec1[ind]<<"  ";
           std::cout<<std::endl;
           std::cout<<"right:"<<std::endl;
           for(int ind=0; ind<Temp_vec2.size();ind++)
                std::cout<<Temp_vec2[ind]<<"  ";
           std::cout<<std::endl;
          
           //actual merge
           int i =0;
           int j =0;
           int k =left;
           while(i < Temp_vec1.size() && j < Temp_vec2.size())
           {
               std::cout<<"Temp_vec1: "<<Temp_vec1[i]<<std::endl;
               std::cout<<"Temp_vec2 "<<Temp_vec2[j]<<std::endl;
               if(Temp_vec1[i]<Temp_vec2[j])
               {
                   input[k] = Temp_vec1[i];
                   k++;
                   i++;
               }
               else
               {
                   input[k] = Temp_vec2[j];
                   k++;
                   j++;
               }
           }
            std::cout<<"merging1:"<<std::endl;
           for(int ind=left; ind<k;ind++)
                std::cout<<input[ind]<<"  ";
           std::cout<<std::endl;
           
           while(i < Temp_vec1.size())
           {
               input[k] = Temp_vec1[i];
               i++;
               k++;
           }
           while(j < Temp_vec2.size())
           {
               input[k] = Temp_vec2[j];
               j++;
               k++;
           }
           

           std::cout<<"merging2:"<<std::endl;
           for(int ind=left; ind<k;ind++)
                std::cout<<input[ind]<<"  ";
           std::cout<<std::endl;
           
       }
       else
            return;
    }
    void output_display()
    {        
        for (int index=0; index < input.size(); index++)
        {
            std::cout<<input[index]<<"  ";
        }
        std::cout<<std::endl;

    }

private:
std::vector<int> input;
};

int main()
{
    std::vector<int> vec1 = {10,0,1,7,8,99};
    MergeSort sort(vec1);
    sort.Sort(vec1,0, vec1.size()-1);
    std::cout<<"final output: "<<std::endl;
    sort.output_display();
    return 0;
}