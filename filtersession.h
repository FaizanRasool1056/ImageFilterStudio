#ifndef FILTERSESSION_H
#define FILTERSESSION_H
#include "filter.h"
#include "image.h"
#include <string>
class filtersession
{
    private:
    filter *pipeline[10]; // for 10 filters we use filter class bcz filter class is parent class of all other children filter class
    int  pipelinecount ; // how many filter added
    image* img; // points to tha image towards it processed
    string customercnic; // to know which customer startted and stored info in session.txt
    string timestamp; // to store time
    string outputfile; // image name after filter act
    public:
    filtersession(string cnic);
    ~filtersession();
    filtersession& addfilter(filter *f); // return this* for chaining
    void setimage(image * img2); 
    void applypipeline(); 
    void saveresult(string path); 
    string getpipelinestr() const; 
    void clearpipeline();
};
#endif 
