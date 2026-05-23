#include "filter.h"
#include "image.h"
#include "filtersession.h"
#include <string>
using namespace std;
// definition of constructor
filtersession::filtersession(string cnic)
{
    customercnic=cnic;
    pipelinecount=0; // started from 0 filter added
    img=nullptr;
    cout<<"SESSION STARTED FOR "<<cnic<<endl;

}
// here metod chaining so that the each filter points to same object
filtersession& filtersession::addfilter(filter*f)
{
  if (pipelinecount <10)
  pipeline[pipelinecount++]=f;
  return *this;// it give current filter session that enables chainining
}
// filter act on curretn image
void filtersession::setimage(image* img2) { 
img= img2; 
} 
// apply pipeline 
void filtersession::applypipeline() 
{ 
    for (int i = 0; i < pipelinecount; i++) 
    { 
        cout << "Applying: " << pipeline[i]->getname() << endl; 
        pipeline[i]->apply(*img); 
        img->displayASCII();
    }
}
// save the results
void filtersession::saveresult(string path) { 
    outputfile = path; 
    img->save(path); 
} 
// get pipeline length
string filtersession::getpipelinestr() const { 
    string result = ""; 
    for (int i = 0; i < pipelinecount; i++) { 
        if (i > 0) result += ">"; 
        result += pipeline[i]->getname(); 
    } 
    return result; 
} 
// for next image
void filtersession::clearpipeline() { 
    pipelinecount = 0; 
} 
// destructor 
filtersession::~filtersession() { 
    cout << "Session ended." << endl; 
}