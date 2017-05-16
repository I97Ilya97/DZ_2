

#include "TTime.h"
//#include <exception>
/*TTime::TTime() {
	// TODO Auto-generated constructor stub

}
*/
/*TTime::~TTime() {
	// TODO Auto-generated destructor stub
}
*/

TTime::TTime(std::string * time)  {

	if(!time){

		throw new std::string("Мне передали нулевой указатель\n");
	}

	//Похожие штуки надо сделать для неподходящих по формату строк


}
