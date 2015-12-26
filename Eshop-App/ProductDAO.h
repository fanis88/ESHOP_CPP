#pragma once
#include <vector>
#include "sqlite3.h"
#include "ProductBase.h"
#include "PC.h"
#include "Smartphone.h"
#include "TV.h"

class ProductDAO sealed
{
public:
	ProductDAO(sqlite3* database);
	int insertPCInDB(PC product, int productType, int availability);
	int insertSmartphoneInDB(Smartphone product, int productType, int availability);
	int insertTVInDB(TV product, int productType, int availability);
	int updatePCInDB(int serial, PC updatedProduct);
	int updateSmartphoneInDB(int serial, Smartphone updatedProduct);
	int updateTVInDB(int serial, TV updatedProduct);
	int updateProductItemsInDB(int serial, int availability);
	int removeProductItemsFromDB(int serial, int removedItems);
	int addProductItemsInDB(int serial, int addedItems);
	int getProductAvailabilityFromDB(int serial);
	ProductBase fetchProductBySerialFromDB(int serial);
	vector<ProductBase> fetchAllProductsFromDB();
private:
	sqlite3* db;
};

