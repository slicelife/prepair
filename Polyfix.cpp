#include "Polyfix.h"

char* validate(char* polygon){
  char *error;
  OGRGeometry *geometry;

  unsigned int bufferSize = 100000000;
  char *inputWKT = (char *)malloc(bufferSize*sizeof(char));
  strcpy(inputWKT, polygon);

  OGRErr err = OGRGeometryFactory::createFromWkt(&inputWKT, NULL, &geometry);
  if (err != OGRERR_NONE) {
    switch (err) {
      case OGRERR_UNSUPPORTED_GEOMETRY_TYPE:
        error = (char *)"Error: geometry must be Polygon or MultiPolygon";
        break;
      case OGRERR_NOT_ENOUGH_DATA:
      case OGRERR_CORRUPT_DATA:
        error = (char *)"Error: corrupted input";
        break;
      default:
        error = (char *)"Error: corrupted input";
        break;
    }
    return error;
  }
  if (geometry->IsEmpty() == 1) {
    error = (char *)"Error: empty geometry";
    return error;
  }
  if ( (geometry->getGeometryType() != wkbPolygon) &&
       (geometry->getGeometryType() != wkbMultiPolygon) ) {
    error = (char *)"Error: geometry must be Polygon or MultiPolygon";
    return error;
  }

  PolygonRepair prepair;
  OGRMultiPolygon *outPolygons;
  outPolygons = prepair.repairOddEven(geometry, 0);

  char *outputWKT;
  outPolygons->exportToWkt(&outputWKT);
  return outputWKT;
}
