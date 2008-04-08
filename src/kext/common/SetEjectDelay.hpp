// -*- indent-tabs-mode: nil; -*-

#ifndef _SetEjectDelay_h
#define _SetEjectDelay_h

#include "base.hpp"

// http://developer.apple.com/documentation/Darwin/Conceptual/KEXTConcept/KEXTConceptIOKit/hello_iokit.html#//apple_ref/doc/uid/20002366-CIHECHHE
class org_pqrs_driver_SetEjectDelay : public IOService
{
  OSDeclareDefaultStructors(org_pqrs_driver_SetEjectDelay);

public:
  virtual bool init(OSDictionary *dictionary = 0);
  virtual void free(void);
  virtual IOService *probe(IOService *provider, SInt32 *score);
  virtual bool start(IOService *provider);
  virtual void stop(IOService *provider);

private:
  static int setEjectDelay(IOHIKeyboard *kbd, int delay);
  static bool notifierfunc_hookKeyboard(org_pqrs_driver_SetEjectDelay *self, void *ref, IOService *newService);
  static bool notifierfunc_unhookKeyboard(org_pqrs_driver_SetEjectDelay *self, void *ref, IOService *newService);

  IONotifier *notifier_hookKeyboard;
  IONotifier *notifier_unhookKeyboard;

  int originalDelay;
};

#endif
