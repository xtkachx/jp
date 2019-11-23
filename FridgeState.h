#ifndef FRIDGESTATE_H
#define FRIDGESTATE_H

#include <QString>

namespace Fridge{

  extern QString modeInitialization;
  extern QString statusStandby;

  extern QString modeFilling;
  extern QString statusFiller;

  extern QString modeService;
  extern QString statusMaintenanceEngineer;

  extern QString modeSale;
  extern QString statusBuyerCanOpenTheDoor;
;

  extern QString statusButtonGoToShopPressed;
  extern QString statusUIDSendToServer;
  extern QString statusUIDNoValid;
  extern QString statusInsolventClient;
  extern QString statusDoorIsOpen;
  extern QString statusReopenDoor;
  extern QString statusDoorIsClose;
  extern QString statusEndOfPurchase;

  extern QString errorNoResponseFromServer;
  extern QString errorDoorIsNotClosed;
}

#endif // FRIDGESITUATION_H
