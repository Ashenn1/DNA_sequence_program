#ifndef PROTEIN_H
#define PROTEIN_H
#include<iomanip>
#include <sequence.h>
#include"DNA.h"
#include<cstring>
#include<iostream>
using namespace std;
enum Protein_Type{Hormon,Enzyme,TF,Cellular_Function};
class CodonsTable;
//class RNA;
class protein : public sequence
{
    private:
        Protein_Type type;
        int startchar;
        int endchar;
    public:
        protein();
        protein(char*p);
        void setseq(char*sequence);
        char*getseq();
         ~protein();
       //DNA*GetDNAStrandsEncodingMe(const DNA & bigDNA);//pass ro it a protien sequence too (takes dna and returns pointer to the possible dnas creating that protien
       void loadsequencefromfile(char*filename);
         void savesequencetofile(char*filename);
         bool operator==(protein &rhs);
            bool operator!=(protein &rhs);
           protein operator+(protein &rhs);
         void print();


    protected:

};

#endif // PROTEIN_H
