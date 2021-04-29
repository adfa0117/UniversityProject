#include "QueType.h"

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max;
  front = 0;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  length = 0;
  minimun_pos = 0;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 500;
  front = 0;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  length = 0;
  minimun_pos = 0;
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = 0;
  rear = maxQue - 1;
  length = 0;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (length == 0);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return (length == maxQue);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
      int point = front;

      for (int i = 0; i < length; ++i)
      {
          if (items[point] == -1)
          {
              items[point] = newItem;
              ++length;
              if (newItem < items[minimun_pos])
              {
                  minimun_pos = point;
              }
              return;
          }
          point = (point + 1) % maxQue;
      }
    rear = (rear +1) % maxQue;
    items[rear] = newItem;
    if (newItem < items[minimun_pos])
    {
        minimun_pos = rear;
    }
    ++length;
  }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    item = items[front];
    front = (front + 1) % maxQue;
    --length;
  }
}

void QueType::MinDequeue(ItemType& item)
{
    int point = front;
    int second_minimun_pos = front;
    ItemType min = items[minimun_pos];
    
    item = min;
    items[minimun_pos] = -1;

    for (int i = 0; i < length;)
    {
        if (items[point] != -1)
        {
            if ((items[point] < items[second_minimun_pos] && items[point] > min) || items[second_minimun_pos] == -1)
            {
                second_minimun_pos = point;
            }

            ++i;
        }

        point = (point + 1) % maxQue;
    }

    minimun_pos = second_minimun_pos;
    
    --length;
}

