// Struct example programs

#include <stdio.h>
#include <stdlib.h>

struct Item
{
	char itemId[100];
	char description[100];
	int price;
}sItem;

void readItem(sItem *pItem)
{
	printf("Enter the ItemId: ");
	scanf("%s", pItem->itemId);
	printf("Enter Description: ");
	scanf("%s", pItem->description);
	printf("Enter price: ");
	scanf("%d", &pItem->price);

}
void printItem(sItem *pItem)
{
	printf("\nItemId: %s", pItem->itemId);
	printf("\nDescription: %s", pItem->description);
	printf("\nPrice: %d", pItem->price);
}
void saveItem(sItem *pItem)
{
	FILE *fpItem;
	fpItem = fopen("Item.txt", "a");
	fwrite(pItem, sizeof(sItem), 1, fpItem);
	fclose(fpItem);
}
void main()
{
	sItem *item = (sItem*) malloc(sizeof(sItem));
	readItem(item);
	printItem(item);
	saveItem(item);
}
