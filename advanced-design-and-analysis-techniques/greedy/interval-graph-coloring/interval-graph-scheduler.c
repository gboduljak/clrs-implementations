#include "../../../data-structures/heaps/min-priority-queue.h"
#include "../../../data-structures/linked-list/linked-list.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct slot
{
  char n;
  int s;
  int f;
  int id;
} slot;

typedef struct schedule_result
{
  int tracks_n;
  linked_list **tracks;
} schedule_result;

int slotsN;
slot *slots;

void print_track(linked_list *track, linked_list_node *node)
{
  if (node == track->nil)
    return;

  print_track(track, node->next);
  printf("%c (%d-%d) ", slots[node->key].n, slots[node->key].s, slots[node->key].f);
}

schedule_result schedule()
{
  if (!slots)
  {
    schedule_result result;
    result.tracks = NULL;
    result.tracks_n = 0;
    return result;
  }

  int tracksN = 1, i;
  priority_queue *tracks_q = AllocateMinPq(slotsN + slotsN);
  linked_list **tracks = (linked_list **)malloc(sizeof(linked_list *) * (slotsN + slotsN));

  for (i = 0; i < slotsN + slotsN; i++)
    tracks[i] = AllocateLinkedList();

  MinPqInsert(tracks_q, tracksN, slots[0].f);
  ListInsert(tracks[tracksN], slots[0].id);

  for (i = 1; i < slotsN; i++)
  {
    priority_queue_element *oldest_track = MinPqExtractMin(tracks_q);

    int oldest_track_finish_time = oldest_track->key;
    int oldest_track_id = oldest_track->id;
    int slot_start_time = slots[i].s;
    int slot_finish_time = slots[i].f;

    if (slot_start_time < oldest_track_finish_time)
    {
      tracksN++;
      MinPqInsert(tracks_q, oldest_track_id, oldest_track_finish_time);
      MinPqInsert(tracks_q, tracksN, slot_finish_time);
      ListInsert(tracks[tracksN], slots[i].id);
    }
    else
    {
      MinPqInsert(tracks_q, oldest_track_id, slot_finish_time);
      ListInsert(tracks[oldest_track_id], slots[i].id);
    }
  }

  DestroyMinPq(tracks_q);

  schedule_result result;
  result.tracks = tracks;
  result.tracks_n = tracksN;
  return result;
}

int main()
{
  int i, s, f;
  char n;

  scanf("%d", &slotsN);
  slots = (slot *)malloc(sizeof(slot) * slotsN);

  for (i = 0; i < slotsN; i++)
  {
    scanf("%d %d", &s, &f);
    slots[i].id = i;
    slots[i].n = n;
    slots[i].s = s;
    slots[i].f = f;
  }

  for (i = 0; i < slotsN; i++)
  {
    scanf(" %c", &n);
    slots[i].n = n;
  }

  printf("loaded slots: \n");
  for (i = 0; i < slotsN; i++)
    printf("name: %c starts: %d finishes: %d\n", slots[i].n, slots[i].s, slots[i].f);

  schedule_result result = schedule();

  printf("required number of tracks is: %d\n", result.tracks_n);
  printf("desired schedule is: \n");

  for (i = 1; i <= result.tracks_n; i++)
  {
    printf("track %d : ", i);
    print_track(result.tracks[i], result.tracks[i]->nil->next);
    printf("\n");
    DellocateLinkedList(result.tracks[i]);
  }

  free(slots);
  free(result.tracks);
}