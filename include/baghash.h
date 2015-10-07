#ifndef __BAGHASH_H__
#define __BAGHASH_H__

#include <stdbool.h>
#include <stddef.h>

enum comp_method {
  COMP__KECCAK_1600,
  COMP__ARGON_BLAKE2B,
  COMP__SHA_512,

  COMP__END
};

// TODO: Add argon mixing method
// TODO: Add parallel two-buffer mixing method
enum mix_method {
  MIX__BAGHASH_ONE_BUFFER
};

struct baghash_options {
  unsigned int m_cost;
  unsigned int t_cost;

  bool xor_then_hash;

  // Degree of expander graph used in the construction.
  // TODO: Make sure that this number is big enough to 
  // get the expansion we need.
  unsigned int n_neighbors;
  enum comp_method comp;
  enum mix_method mix;
};

int BagHash (void *out, size_t outlen, const void *in, size_t inlen, 
    const void *salt, size_t saltlen, 
    struct baghash_options *opts);

#endif /* __BAGHASH_H__ */

