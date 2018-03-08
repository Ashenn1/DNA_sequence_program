#include "CodonsTable.h"
#include<fstream>
#include<iostream>
using namespace std;

CodonsTable::CodonsTable()
{
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<4; j++)
        {
            codons[i].value[j]='\0';
            codons[i].AminoAcid='\0';
        }
    }

}
void CodonsTable::loadcodonsfromfile(char* filename)
{
    char c;
    int count=0;
    ifstream infile;
    infile.open(filename);
    if(infile)
    {
        for(int i=0; i<64; i++)
        {
            for(int j=0; j<4; j++)
            {
                infile>>c;

                if(count==3)
                {
                    codons[i].AminoAcid=c;
                    count=0;
                    continue;
                }
                codons[i].value[j]=c;
                count++;
            }
        }
    }
    else
        cout<<"Error opening file."<<endl;
}

codon CodonsTable:: getaminoacid(char*value) const
{
    int truee;
    for(int i=0; i<64; i++)
    {
        truee=0;
        for(int j=0; j<3; j++)
            if((codons[i].value[j])==value[j])
            {
                truee++;
                if(truee==3)
                {
                    return codons[i];//have to return the whole struct not the aminoacid part only,in the main receive them then get the aminoacid part alone
                }

            }
    }


}

void CodonsTable:: setcodon(char*value,char AminoAcid,int index)
{
    int count=0;
    for(int j=0; j<4; j++)
    {
        if(count==3)
        {
            codons[index].AminoAcid=AminoAcid;
            count=0;
            continue;
        }
        codons[index].value[j]=value[j];
        count++;
    }
}


CodonsTable::~CodonsTable()
{
    //dtor
}
