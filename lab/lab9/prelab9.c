//prelab 9 sample code by alex lobzhanidze
#include "bst.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("usage: %s <input_filename>\n", argv[0]);
		return 0;
	}
	
	FILE *in = fopen(argv[1], "r");
	if (in == NULL) return 0;
	
	int i, size;
	fscanf(in, "%d", &size);
	int *array = malloc(size * sizeof(int));
	
	for (i=0; i<size; i++)
		fscanf(in, "%d", &array[i]);
	
	bst *root = NULL;
	for (i=0; i<size; i++)
		root = insert(root, array[i]);

	//print in-order tree traversal
	printf("Tree in-order traversal: "); 
	printInorder(root); 
	printf("\n");

 return 0;
}
