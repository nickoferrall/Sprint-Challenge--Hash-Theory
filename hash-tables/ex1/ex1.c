#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"
#include <ctype.h>

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  if (length <= 1)
  {
    return NULL;
  }

  for (int i = 0; i < length; i++)
  {
    int to_search = limit - weights[i];
    if (hash_table_retrieve(ht, to_search) == -1)
    {
      hash_table_insert(ht, weights[i], i);
    }
    // if it's not -1, we've got the right values
    else
    {
      Answer *answer = malloc(sizeof(Answer));
      if (i > hash_table_retrieve(ht, to_search))
      {
        answer->index_1 = i;
        answer->index_2 = hash_table_retrieve(ht, to_search);
      }
      else
      {
        answer->index_1 = hash_table_retrieve(ht, to_search);
        answer->index_2 = i;
      }
      destroy_hash_table(ht);
      return answer;
    }
  }

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}
#endif
