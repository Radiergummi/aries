
#ifndef AIRES_IMPL_REDIS_H
#define AIRES_IMPL_REDIS_H

#include "../cache.hpp"

#include <hiredis/hiredis.h>

namespace aries {
namespace cache {
class Redis : public Cache {
public:
  Redis(const char *prefix, const char *host, int port, int db, int timeout);
  ~Redis();
  void set(const char *key, const char *val, uint ttl);
  const char *get(const char *key);
  void del(const char *key);
  std::vector<const char *> keys();

private:
  redisContext *ctx;
  const char *prefix;
};
}
}

#endif