#include<fstream>
#include<string.h>
#include<iostream>

using namespace std;

#define MAXIMUM 256
#define MAX 5000
#define OFFSET 16

int main(int argc,char *argv[])
{
	char *part1=new char[MAX];
	char *part2=new char[MAX];
	char *buffer=new char[MAXIMUM];
	fstream fr;
	fr.open("/etc/dtn.conf",ios::in | ios::out);
	if(!fr)
	{
		printf("/etc/dtn.config is not exist,error\n");
	    delete [] buffer;
		return 0;
	}
	const char *d = " \t";
	char *strArray;
	int location_last=0;
	int location=0;
	int length;
    while(!fr.eof() )
    {
    	fr.getline (buffer,MAXIMUM);
	    location=fr.tellg();
    	strArray=strtok(buffer,d);

    	if(strArray!=NULL && !strcmp(strArray,"route"))
		{
		    strArray=strtok(NULL,d);
			if(!strcmp(strArray,"local_eid"))
			{
			    strArray=strtok(NULL,d);
				int i,j;
			    for(i=0;strArray[i]!='\0';++i)
			    	;
			    length=i;
			    for(j=1;j<i-1;++j)
			    	strArray[j-1]=strArray[j];
			    strArray[j-1]='\0';
			    printf("old name : %s",strArray);
			    break;
			}
		}
    	location_last=location;
    }
    fr.seekg(0,ios::beg);
    fr.read(part1,location_last);
    fr.seekg(0,ios::end);
    int end=fr.tellg();
    location--;
    fr.seekg(location,ios::beg);
    fr.read(part2,end-location);
    fr.close();
    string s="route local_eid \"";
    s+=*++argv;
    s+="\"";
    for(int i=0;i<s.size();++i)
    	part1[location_last+i]=s[i];
	fr.open("/etc/dtn.conf",ios::out | ios::trunc);
	fr.write(part1,location_last+s.size());
	fr.close();

	fr.open("/etc/dtn.conf",ios::out | ios::app);
	fr.write(part2,end-location);
    fr.close();
    delete [] part1;
    delete [] part2;
    delete [] buffer;
    return 0;
}
