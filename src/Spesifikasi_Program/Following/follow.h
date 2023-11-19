#ifndef __FOLLOW_H__
#define __FOLLOW_H__

#include "../../ADT/graph/graph.h"
#include "../../ADT/pcolor/pcolor.h"

#include "../Play/Play.h"
#include "../MultiUser/MultiUser.h"

void FollowFriend(DataUser * DU, CurrentUser * CU);

void ListFollowing(DataUser * DU, CurrentUser * CU);

int CheckFriend(adrNode P, int idUser);

adrNode AddressGraph(DataUser * DU, CurrentUser * CU);

#endif