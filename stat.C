#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
   struct stat sb;

   if (argc != 2) {
       cerr <<  "Usage: " << argv[0] << " <pathname>" << endl;
       exit(EXIT_FAILURE);
   }

   if (lstat(argv[1], &sb) == -1) {
       perror("lstat");
       exit(EXIT_FAILURE);
   }

   cout << "ID of containing device: "<< major(sb.st_dev) << "," << minor(sb.st_dev) << endl;

   cout << "File type: " << endl;

   switch (sb.st_mode & S_IFMT) {
	case S_IFDIR:  
		cout << "directory" << endl;
	   	break;
	case S_IFLNK:  
	   	cout << "symbolic link" << endl;
	   	break;
   	case S_IFREG: 
		cout << "regular file" << endl;       
		break;
     	default:      
	       cout << "something else" << endl;
   }
   
   cout << setw(13) << "inodenumber: " << sb.st_ino << endl; 
   cout << setw(13) << "Mode: " << sb.st_mode << endl;
   cout << setw(13) << "Owner: " << sb.st_uid << endl;

   exit(EXIT_SUCCESS);
}
