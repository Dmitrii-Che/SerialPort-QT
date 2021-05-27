//#define Calculation

#include "serialportworker.h"
#include <QApplication>

#ifdef Calculation
void QByteArrayintToBytes(int paramInt)
{
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream << paramInt;
    //return array;
}

void wait_for_anykey()
{
    char ch1;
    std::cin >> ch1;
}

void printfBinary(const int &value, const std::string &str = "", const int &size = 33)
{
    int offset, actualSize = 0, partition = 4;
    char buffer[size];
    char ch;
    itoa(value, buffer, 2);

    do {
        ch = buffer[actualSize];
        actualSize++;
    }   while(ch != '\0');

    actualSize--;

    actualSize  % partition != 0 ? offset = partition - actualSize % partition : offset = /*-1*/0;

    int tempSize = actualSize + actualSize / partition + offset;
    char tempBuffer[tempSize];

    for(int tempN = tempSize, buffN = actualSize, k = partition + 1; tempN >= 0; tempN--)  {

        if(k > 0) {
            if(buffN >= 0) {
                tempBuffer[tempN] = buffer[buffN];
            }
            else {
                tempBuffer[tempN] = '0';
            }

            buffN--;
            k--;
        }
        else {
            tempBuffer[tempN] = ' ';
            k = partition;
        }

    }

    tempBuffer[tempSize] = '\0';


    //         printf("\n%u ^%u", actualSize, offset);
    //         printf("\n\n %s 1: %s", str.c_str(), buffer);
    //         printf("\n %s: 0x%X = \n\t\t%s\n", str.c_str(), value, tempBuffer);
    //         printf("\n %s", tempBuffer);
    printf("  >>%s %s\n", str.c_str(), tempBuffer);

}
#endif
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    SerialPortWorker w;
    w.show();
    //    w.initPort();
    return a.exec();
}
