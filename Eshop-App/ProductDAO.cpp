#include "pch.h"
#include "ProductDAO.h"

ProductDAO::ProductDAO(sqlite3* database) {
	db = database;
}

int ProductDAO::insertPCInDB(PC product, int productType, int availability) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "insert into products (TYPE, SERIAL, PRICE, MODEL, MANUFACTURER, " \
		"PHOTOURL, DESCRIPTION, RAM, CPU, DISKTYPE, DISKSPACE, GPU, SCREENSIZE" \
		"BATTERYLIFE, CANRECORD4K, CANSHOW3D)" \
		"values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ? )";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(stmt, 1, 0);
		sqlite3_bind_int(stmt, 2, product.getSerial());
		sqlite3_bind_double(stmt, 3, product.getPrice());
		sqlite3_bind_text(stmt, 4, product.getModel(), strlen(product.getModel()), 0);
		sqlite3_bind_text(stmt, 5, product.getManufacturer(), strlen(product.getManufacturer()), 0);
		sqlite3_bind_text(stmt, 6, product.getPhotoUrl(), strlen(product.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, 7, product.getDescription(), strlen(product.getDescription()), 0);
		sqlite3_bind_int(stmt, 8, product.getRam());
		sqlite3_bind_double(stmt, 9, product.getCpu());
		sqlite3_bind_text(stmt, 10, product.getDiskType(), strlen(product.getDiskType()), 0);
		sqlite3_bind_int(stmt, 11, product.getDiskSpace());
		sqlite3_bind_text(stmt, 12, product.getGpu(), strlen(product.getGpu()), 0);

		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::insertSmartphoneInDB(Smartphone product, int productType, int availability) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "insert into products (TYPE, SERIAL, PRICE, MODEL, MANUFACTURER, " \
		"PHOTOURL, DESCRIPTION, RAM, CPU, DISKTYPE, DISKSPACE, GPU, SCREENSIZE" \
		"BATTERYLIFE, CANRECORD4K, CANSHOW3D)" \
		"values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ? )";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(stmt, 1, 0);
		sqlite3_bind_int(stmt, 2, product.getSerial());
		sqlite3_bind_double(stmt, 3, product.getPrice());
		sqlite3_bind_text(stmt, 4, product.getModel(), strlen(product.getModel()), 0);
		sqlite3_bind_text(stmt, 5, product.getManufacturer(), strlen(product.getManufacturer()), 0);
		sqlite3_bind_text(stmt, 6, product.getPhotoUrl(), strlen(product.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, 7, product.getDescription(), strlen(product.getDescription()), 0);
		sqlite3_bind_double(stmt, 13, product.getScreenSize());
		sqlite3_bind_int(stmt, 14, product.getBatteryLife());
		sqlite3_bind_int(stmt, 15, product.getCanRecord4k());

		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::insertTVInDB(TV product, int productType, int availability) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "insert into products (TYPE, SERIAL, PRICE, MODEL, MANUFACTURER, " \
		"PHOTOURL, DESCRIPTION, RAM, CPU, DISKTYPE, DISKSPACE, GPU, SCREENSIZE" \
		"BATTERYLIFE, CANRECORD4K, CANSHOW3D)" \
		"values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ? )";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(stmt, 1, 0);
		sqlite3_bind_int(stmt, 2, product.getSerial());
		sqlite3_bind_double(stmt, 3, product.getPrice());
		sqlite3_bind_text(stmt, 4, product.getModel(), strlen(product.getModel()), 0);
		sqlite3_bind_text(stmt, 5, product.getManufacturer(), strlen(product.getManufacturer()), 0);
		sqlite3_bind_text(stmt, 6, product.getPhotoUrl(), strlen(product.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, 7, product.getDescription(), strlen(product.getDescription()), 0);
		sqlite3_bind_double(stmt, 13, product.getScreenSize());
		sqlite3_bind_int(stmt, 16, product.getCanShow3d());

		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::updatePCInDB(int serial, PC updatedProduct) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "update products set PRICE = ?, MODEL = ?, " \
		"MANUFACTURER = ?, PHOTOURL = ?, DESCRIPTION = ?, RAM = ?, CPU = ?, " \
		"DISKTYPE = ?, DISKSPACE = ?, GPU = ?, SCREENSIZE = ?, BATTERYLIFE = ?, " \
		"CANRECORD4K = ?, CANSHOW3D = ? WHERE SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_double(stmt, 1, updatedProduct.getPrice());
		sqlite3_bind_text(stmt, 2, updatedProduct.getModel(), strlen(updatedProduct.getModel()), 0);
		sqlite3_bind_text(stmt, 3, updatedProduct.getManufacturer(), strlen(updatedProduct.getManufacturer()), 0);
		sqlite3_bind_text(stmt, 4, updatedProduct.getPhotoUrl(), strlen(updatedProduct.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, 5, updatedProduct.getDescription(), strlen(updatedProduct.getDescription()), 0);
		sqlite3_bind_int(stmt, 6, updatedProduct.getRam());
		sqlite3_bind_double(stmt, 7, updatedProduct.getCpu());
		sqlite3_bind_text(stmt, 8, updatedProduct.getDiskType(), strlen(updatedProduct.getDiskType()), 0);
		sqlite3_bind_int(stmt, 9, updatedProduct.getDiskSpace());
		sqlite3_bind_text(stmt, 10, updatedProduct.getGpu(), strlen(updatedProduct.getGpu()), 0);
		sqlite3_bind_int(stmt, 15, updatedProduct.getSerial());
		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::updateSmartphoneInDB(int serial, Smartphone updatedProduct) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "update products set PRICE = ?, MODEL = ?, " \
		"MANUFACTURER = ?, PHOTOURL = ?, DESCRIPTION = ?, RAM = ?, CPU = ?, " \
		"DISKTYPE = ?, DISKSPACE = ?, GPU = ?, SCREENSIZE = ?, BATTERYLIFE = ?, " \
		"CANRECORD4K = ?, CANSHOW3D = ? WHERE SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_double(stmt, 1, updatedProduct.getPrice());
		sqlite3_bind_text(stmt, 2, updatedProduct.getModel(), strlen(updatedProduct.getModel()), 0);
		sqlite3_bind_text(stmt, 3, updatedProduct.getManufacturer(), strlen(updatedProduct.getManufacturer()), 0);
		sqlite3_bind_text(stmt, 4, updatedProduct.getPhotoUrl(), strlen(updatedProduct.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, 5, updatedProduct.getDescription(), strlen(updatedProduct.getDescription()), 0);
		sqlite3_bind_double(stmt, 11, updatedProduct.getScreenSize());
		sqlite3_bind_int(stmt, 12, updatedProduct.getBatteryLife());
		sqlite3_bind_int(stmt, 13, updatedProduct.getCanRecord4k());
		sqlite3_bind_int(stmt, 15, updatedProduct.getSerial());
		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::updateTVInDB(int serial, TV updatedProduct) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "update products set PRICE = ?, MODEL = ?, " \
		"MANUFACTURER = ?, PHOTOURL = ?, DESCRIPTION = ?, RAM = ?, CPU = ?, " \
		"DISKTYPE = ?, DISKSPACE = ?, GPU = ?, SCREENSIZE = ?, BATTERYLIFE = ?, " \
		"CANRECORD4K = ?, CANSHOW3D = ? WHERE SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_double(stmt, 1, updatedProduct.getPrice());
		sqlite3_bind_text(stmt, 2, updatedProduct.getModel(), strlen(updatedProduct.getModel()), 0);
		sqlite3_bind_text(stmt, 3, updatedProduct.getManufacturer(), strlen(updatedProduct.getManufacturer()), 0);
		sqlite3_bind_text(stmt, 4, updatedProduct.getPhotoUrl(), strlen(updatedProduct.getPhotoUrl()), 0);
		sqlite3_bind_text(stmt, 5, updatedProduct.getDescription(), strlen(updatedProduct.getDescription()), 0);
		sqlite3_bind_double(stmt, 11, updatedProduct.getScreenSize());
		sqlite3_bind_int(stmt, 14, updatedProduct.getCanShow3d());
		sqlite3_bind_int(stmt, 15, updatedProduct.getSerial());
		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::updateProductItemsInDB(int serial, int availability) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "update in products set AVAILABILITY = ? where SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(stmt, 1, availability);
		sqlite3_bind_int(stmt, 2, serial);
		int res = sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return res;
	}

	return 0;
}

int ProductDAO::removeProductItemsFromDB(int serial, int removedItems) {
	int productAvailability = getProductAvailabilityFromDB(serial);
	productAvailability -= removedItems;
	int res = updateProductItemsInDB(serial, productAvailability);

	return res;
}

int ProductDAO::addProductItemsInDB(int serial, int addedItems) {
	int productAvailability = getProductAvailabilityFromDB(serial);
	productAvailability += addedItems;
	int res = updateProductItemsInDB(serial, productAvailability);

	return res;
}

int ProductDAO::getProductAvailabilityFromDB(int serial) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return 0;
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "select AVAILABILITY from products where SERIAL = ?";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(stmt, 1, serial);
		int res = 0;

		res = sqlite3_step(stmt);
		if (res == SQLITE_ROW) {
			int availability = sqlite3_column_int(stmt, 1);
			sqlite3_finalize(stmt);
			return availability;
		}
		else if (res == SQLITE_DONE) {
			fprintf(stderr, "No product with given serial number.");
			return res;
		}
		else {
			fprintf(stderr, "Database error while fetching product.");
			return res;
		}
	}
	return 0;
}

ProductBase ProductDAO::fetchProductBySerialFromDB(int serial) {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		ProductBase product;
		return product;
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	szSQL = "SELECT * from products where serial=:serial";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		sqlite3_bind_int(stmt, 1, serial);
		int res = 0;

		res = sqlite3_step(stmt);
		if (res == SQLITE_ROW) {
			if (sqlite3_column_int(stmt, 1) == 0)			//Product type: PC
			{
				PC fetchedProduct = PC(sqlite3_column_int(stmt, 2), sqlite3_column_double(stmt, 3));
				fetchedProduct.setModel((char*)sqlite3_column_text(stmt, 4));
				fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, 5));
				fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, 6));
				fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, 7));
				fetchedProduct.setRam(sqlite3_column_int(stmt, 8));
				fetchedProduct.setCpu(sqlite3_column_double(stmt, 9));
				fetchedProduct.setDiskType((char*)sqlite3_column_text(stmt, 10));
				fetchedProduct.setDiskSpace(sqlite3_column_int(stmt, 11));
				fetchedProduct.setGpu((char*)sqlite3_column_text(stmt, 12));
				sqlite3_finalize(stmt);
				return fetchedProduct;
			}
			else if (sqlite3_column_int(stmt, 1) == 1) {	//Product type: Smartphone
				Smartphone fetchedProduct = Smartphone(sqlite3_column_int(stmt, 2), sqlite3_column_double(stmt, 3));
				fetchedProduct.setModel((char*)sqlite3_column_text(stmt, 4));
				fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, 5));
				fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, 6));
				fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, 7));
				fetchedProduct.setScreenSize(sqlite3_column_double(stmt, 13));
				fetchedProduct.setBatteryLife(sqlite3_column_int(stmt, 14));
				fetchedProduct.setCanRecord4k(sqlite3_column_int(stmt, 15));
				sqlite3_finalize(stmt);
				return fetchedProduct;
			}
			else {											//Product type: TV
				TV fetchedProduct = TV(sqlite3_column_int(stmt, 2), sqlite3_column_double(stmt, 3));
				fetchedProduct.setModel((char*)sqlite3_column_text(stmt, 4));
				fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, 5));
				fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, 6));
				fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, 7));
				fetchedProduct.setScreenSize(sqlite3_column_double(stmt, 13));
				fetchedProduct.setCanShow3d(sqlite3_column_int(stmt, 16));
				sqlite3_finalize(stmt);
				return fetchedProduct;
			}
		}
		else if (res == SQLITE_DONE) {
			fprintf(stderr, "No product with given serial number.");
			ProductBase product;
			return product;
		}
		else {
			fprintf(stderr, "Database error while fetching product.");
			ProductBase product;
			return product;
		}
	}
}

vector<ProductBase> ProductDAO::fetchAllProductsFromDB() {
	if (!db) {
		fprintf(stderr, "Invalid or unset database.");
		return vector<ProductBase>();
	}

	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;
	vector <ProductBase> products;

	szSQL = "SELECT * from products";
	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {
		int res = 0;

		while (1) {
			res = sqlite3_step(stmt);
			if (res == SQLITE_ROW) {
				if (sqlite3_column_int(stmt, 1) == 0)			//Product type: PC
				{
					PC fetchedProduct = PC(sqlite3_column_int(stmt, 2), sqlite3_column_double(stmt, 3));
					fetchedProduct.setModel((char*)sqlite3_column_text(stmt, 4));
					fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, 5));
					fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, 6));
					fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, 7));
					fetchedProduct.setRam(sqlite3_column_int(stmt, 8));
					fetchedProduct.setCpu(sqlite3_column_double(stmt, 9));
					fetchedProduct.setDiskType((char*)sqlite3_column_text(stmt, 10));
					fetchedProduct.setDiskSpace(sqlite3_column_int(stmt, 11));
					fetchedProduct.setGpu((char*)sqlite3_column_text(stmt, 12));
					sqlite3_finalize(stmt);
					products.push_back(fetchedProduct);
				}
				else if (sqlite3_column_int(stmt, 1) == 1) {	//Product type: Smartphone
					Smartphone fetchedProduct = Smartphone(sqlite3_column_int(stmt, 2), sqlite3_column_double(stmt, 3));
					fetchedProduct.setModel((char*)sqlite3_column_text(stmt, 4));
					fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, 5));
					fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, 6));
					fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, 7));
					fetchedProduct.setScreenSize(sqlite3_column_double(stmt, 13));
					fetchedProduct.setBatteryLife(sqlite3_column_int(stmt, 14));
					fetchedProduct.setCanRecord4k(sqlite3_column_int(stmt, 15));
					sqlite3_finalize(stmt);
					products.push_back(fetchedProduct);
				}
				else {											//Product type: TV
					TV fetchedProduct = TV(sqlite3_column_int(stmt, 2), sqlite3_column_double(stmt, 3));
					fetchedProduct.setModel((char*)sqlite3_column_text(stmt, 4));
					fetchedProduct.setManufacturer((char*)sqlite3_column_text(stmt, 5));
					fetchedProduct.setPhotoUrl((char*)sqlite3_column_text(stmt, 6));
					fetchedProduct.setDescription((char*)sqlite3_column_text(stmt, 7));
					fetchedProduct.setScreenSize(sqlite3_column_double(stmt, 13));
					fetchedProduct.setCanShow3d(sqlite3_column_int(stmt, 16));
					sqlite3_finalize(stmt);
					products.push_back(fetchedProduct);
				}
			}
			if (res == SQLITE_DONE || res == SQLITE_ERROR)
			{
				break;
			}
		}
	}
	return products;
}