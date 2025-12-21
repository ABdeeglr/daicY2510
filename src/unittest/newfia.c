#include "../fia/fia.h"

int main(const int argc, const char** argv) {
  FiaPackageMethods Fia = FiaPackageTopMethod_Initialize();
  iamResult res =  Fia.create(20);
  Array arr;
  if (res.status == SUCCESS) arr = res.value;
  Fia.fillRandomWithBound(arr, Fia.getCapacity(arr) << 4);
  Fia.display(arr);
  Fia.destroy(arr);
  return 0;
}
