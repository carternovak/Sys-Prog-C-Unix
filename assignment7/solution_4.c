#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char* catalog = 
	"<catalog>\n"
	"<book id=\"bk101\">\n"
"<author>Gambardella, Matthew</author>\n"
"<title>XML Developer's Guide</title>\n"
"<genre>Computer</genre>\n"
"<price>44.95</price>\n"
"<publish_date>2000-10-01</publish_date>\n"
"<description>An in-depth look at creating applications\n"
"with XML.</description>\n"
"</book>\n"
"<book id=\"bk102\">\n"
"<author>Cormen, Stein</author>\n"
"<title>Introduction to Algorithm, fourth edition</title>\n"
"<genre>Computer</genre>\n"
"<price>84.49</price>\n"
"<publish_date>2022-04-05</publish_date>\n"
"<description>A comprehensive update of the leading algorithms text, with new material\n"
"on matchings in bipartite graphs, online algorithms, machine learning, and other\n"
"topics.</description>\n"
"</book>\n"
"<book id=\"bk103\">\n"
"<author>Carl Ryan</author>\n"
"<title>Python Programming for Beginners: A Crash Course</title>\n"
"<genre>Computer</genre>\n"
"<price>7.11</price>\n"
"<publish_date>2022-01-19</publish_date>\n"
"<description>The ultimate guide for beginners</description>\n"
"</book>\n"
"</catalog>";

	typedef struct {
	char* author;
	char* title;
	char* genre;
	float price;
	char* publish_date;
	char* description;
	char* id;
	} book;

	book* books = NULL;
	int num_books = 0;

	char* ptr = catalog;
	char* start, *end;

	while (1) {
		start = strstr(ptr, "<book");
		if (start == NULL) 
			break;
		
		start = strstr(start, "id=\"");
		if (start == NULL) 
			break;
		start += 4;
		
	
		end = strchr(start, '"');
		if (end == NULL) 
			break;

		num_books++;
		books = realloc(books, sizeof(book) * num_books);
		int len = end - start;
		books[num_books-1].id = malloc(len + 1);
		strncpy(books[num_books-1].id, start, len);
		books[num_books-1].id[len] = '\0';

		ptr = end + 1;
	}
	//free(start);
	//free(ptr);
	//free(end);
	char* ptr1 = catalog;
	char* start1, *end1;
	int k = 0;
	while(k < num_books){
		start1 = strstr(ptr1, "<author");
		if (start1 == NULL)
			break;

		start1 = strstr(start1, ">");
		if (start1 == NULL)
			break;	
		start1 += 1;
		end1 = strchr(start1, '<');
		if (end1 == NULL)
			break;

		int len = end1 - start1;
		books[k].author = malloc(len + 1);
		strncpy(books[k].author, start1, len);
		books[k].author[len] = '\0';
		k++;
		ptr1 = end1 + 1;
	}

	
	char* ptr2 = catalog;
	char* start2, *end2;
	int a = 0;
	while(a < num_books){
		start2 = strstr(ptr2, "<title");
		if (start2 == NULL)
			break;

		start2 = strstr(start2, ">");
		if (start2 == NULL)
			break;	
		start2 += 1;
		end2 = strchr(start2, '<');
		if (end2 == NULL)
			break;

		int len = end2 - start2;
		books[a].title = malloc(len + 1);
		strncpy(books[a].title, start2, len);
		books[a].title[len] = '\0';
		a++;
		ptr2 = end2 + 1;
	}

	//free(start2);
	//free(ptr2);
	//free(end2);
	char* ptr3 = catalog;
	char* start3, *end3;
	int b = 0;
	while(b < num_books){
		start3 = strstr(ptr3, "<genre");
		if (start3 == NULL)
			break;

		start3 = strstr(start3, ">");
		if (start3 == NULL)
			break;	
		start3 += 1;
		end3 = strchr(start3, '<');
		if (end3 == NULL)
			break;

		int len = end3 - start3;
		books[b].genre = malloc(len + 1);
		strncpy(books[b].genre, start3, len);
		books[b].genre[len] = '\0';
		b++;
		ptr3 = end3 + 1;
	}

	//free(start3);
	//free(ptr3);
	//free(end3);
	char* ptr4 = catalog;
	char* start4, *end4;
	char *fptr;
	int c = 0;
	while(c < num_books){
		start4 = strstr(ptr4, "<price");
		if (start4 == NULL)
			break;

		start4 = strstr(start4, ">");
		if (start4 == NULL)
			break;	
		start4 += 1;
		end4 = strchr(start4, '<');
		if (end4 == NULL)
			break;

		int len = end4 - start4;
		char *string = malloc(len + 1);
		strncpy(string, start4, len);
		books[c].price = strtof(string, &fptr);
		//books[c].price[len] = '\0';
		c++;
		ptr4 = end4 + 1;
	}

	//free(start4);
	//free(ptr4);
	//free(end4);
	char* ptr5 = catalog;
	char* start5, *end5;
	int d = 0;
	while(d < num_books){
		start5 = strstr(ptr5, "<publish_date");
		if (start5 == NULL)
			break;

		start5 = strstr(start5, ">");
		if (start5 == NULL)
			break;	
		start5 += 1;
		end5 = strchr(start5, '<');
		if (end5 == NULL)
			break;

		int len = end5 - start5;
		books[d].publish_date = malloc(len + 1);
		strncpy(books[d].publish_date, start5, len);
		books[d].publish_date[len] = '\0';
		d++;
		ptr5 = end5 + 1;
	}

	//free(start5);
	//free(ptr5);
	//free(end5);
	char* ptr6 = catalog;
	char* start6, *end6;
	int e = 0;
	while(e < num_books){
		start6 = strstr(ptr6, "<description");
		if (start6 == NULL)
			break;

		start6 = strstr(start6, ">");
		if (start6 == NULL)
			break;	
		start6 += 1;
		end6 = strchr(start6, '<');
		if (end6 == NULL)
			break;

		int len = end6 - start6;
		books[e].description = malloc(len + 1);
		strncpy(books[e].description, start6, len);
		books[e].description[len] = '\0';
		e++;
		ptr6 = end6 + 1;
	
	}
	
	if (num_books == 0) {
	printf("No books found\n");
	return 0;
	}
	/*
	int i;
	for (i = 0; i < num_books; i++) {
		printf("Book %d:\n", i+1);
		printf("ID: %s\n", books[i].id);
		printf("Author: %s\n", books[i].author);
		printf("Title: %s\n", books[i].title);
		printf("Genre: %s\n", books[i].genre);
		printf("Price: %.2f\n", books[i].price);
		printf("Publication Date: %s\n", books[i].publish_date);
		printf("Description: %s\n", books[i].description);
		printf("\n");
		}
	*/
	float max = 0;
	float min = 10000;
	int maxIndex, minIndex;
	for(int i = 0; i < num_books; i++){
		if(books[i].price > max){
			max = books[i].price;
			maxIndex = i;
		}
		else if(books[i].price < min){
			min = books[i].price;
			minIndex = i;
		}

	}
	// MOST EXPENSIVE
	printf("Most Expensive Book: \n");
	printf("Author: %s\n", books[maxIndex].author);
	printf("Title: %s\n", books[maxIndex].title);
	printf("Genre: %s\n", books[maxIndex].genre);
	printf("Price: %.2f\n", books[maxIndex].price);
	printf("Publication Date: %s\n", books[maxIndex].publish_date);
	printf("Description: %s\n", books[maxIndex].description);
	printf("\n");

	printf("Least Expensive Book: \n");
	printf("Author: %s\n", books[minIndex].author);
	printf("Title: %s\n", books[minIndex].title);
	printf("Genre: %s\n", books[minIndex].genre);
	printf("Price: %.2f\n", books[minIndex].price);
	printf("Publication Date: %s\n", books[minIndex].publish_date);
	printf("Description: %s\n", books[minIndex].description);
	printf("\n");
		
	return 0;
	}
