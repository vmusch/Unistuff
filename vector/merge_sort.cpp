#include <csignal>
#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

template<typename T>
std::vector<T> merge(std::vector<T>& llist, std::vector<T>& rlist){
  size_t listSize = llist.size()+rlist.size();
  std::vector<T> list(listSize);
  size_t il = 0; 
  size_t ir = 0;
  for(size_t i = 0; i < listSize; i++){
    if(il >= llist.size()){
      list[i] = rlist[ir];
      ir++;
    }
    else if (ir >= rlist.size()){
      list[i] = llist[il];
      il++;
    }
    else if(llist.at(il) <= rlist.at(ir)){
      list[il+ir] = llist[il];
      il++;    
    }
    else
    {
      list[il+ir] = rlist[ir];
      ir++;
    }
  }
  return list;
}

template<typename T>
std::vector<T> mergeSort (std::vector<T> &list){
  if (list.size() <= 1) {
    return list;
  }
  else {
    size_t h = list.size()/2;
    size_t m = list.size()%2;
    std::vector<T> llist(list.begin(), list.end()-h-m);
    std::vector<T> rlist(list.begin()+h, list.end());
    llist = mergeSort(llist);
    rlist = mergeSort(rlist);
    return merge(llist, rlist);
  }
}

template<typename T>
void printVec(std::vector<T>& in){
  for(size_t i = 0; i < in.size(); i++){
    std::cout<<in[i]<<" ";
  }
  std::cout<<std::endl;
}

int main(){
  std::vector<int> a {11,5,6,8,7,9,7,46,8,689,10};
  printVec(a);
  std::vector<int> b = mergeSort(a);
  printVec(b);
  std::vector<std::string> c {"a","g","e","l"};
  printVec(c);
  std::vector<std::string> d = mergeSort(c);
  printVec(d);
  return 0;
}
