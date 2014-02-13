#include "SkipList.hpp"

/***********************************************************/
/********************** PROVIDED FUNCTIONS *****************/
/***********************************************************/

void SkipList::init(int maxHeight) {
    m_maxHeight = maxHeight;
    m_head = new SkipListNode("", m_maxHeight);
}

SkipList::~SkipList() {
    while (m_head != NULL) {
        SkipListNode* head = m_head;
        m_head = m_head->nextAtLevel(0);
        delete head;
    }
}

int SkipList::add(const Key& key, bool verbose) {
    if (find(key, false)) {
        if (verbose) {
            cout << "Node " << key << " is already in the list." << endl;
        }
        return 0;
    }

    SkipListNode* newNode = new SkipListNode(key, randHeight());
    if (verbose) {
        cout << "Add new node "<< *newNode << " with height "
             << newNode->height() << endl;
    }
    int ret = add(m_head, newNode, m_maxHeight - 1);
    if (ret == 0) {
        return ret;
    }
    return 1;
}

/*           DELETE   */

int SkipList::addToHeadTest(int level, SkipListNode* newNode) {

    m_head->setNextAtLevel(level, newNode);

    return 1;
}

/*      */

int SkipList::find(const Key& key, bool verbose) {
    SkipListNode* ret = find(m_head, key, m_maxHeight - 1) ;
    if (ret == NULL) {
        if (verbose) {
            cout<< "Node "<< key << " is not in the list" << endl;
        }
        return 0;
    } else {
        if (verbose) {
            cout<< "Node " << key << " is in the list" << endl;
        }
        return 1;
    }

}
int SkipList::del(const Key& key, bool verbose) {
    if (key.length() == 0){
      return 1;
    }
    SkipListNode* toBeDeleted = del(m_head, key, m_maxHeight - 1);

    if (toBeDeleted == NULL) {
        if (verbose) {
            cout<< "Node " << key << " is not in the list" << endl;
        }
    } else {
        delete toBeDeleted;
        if (verbose) {
            cout << "Node " << key << " is deleted from the list" << endl;
        }
    }
    return 1;
}

void SkipList::dump(char sep) {
    int length = -1;
    cout << "Current List: ";
    for (SkipListNode* iter = m_head; iter != NULL; iter = iter->nextAtLevel(0)) {
        length++;
        cout << string(*iter) << " ";
        cout << "(" << iter->height() << ":";
        for (unsigned i = 0; i < iter->height(); i++) {
            if (iter->nextAtLevel(i)) {
                cout << " "<< i << ":" << *(iter->nextAtLevel(i));
                cout.flush();
            }
        }
        cout << ")" << sep;
    }
    cout << length << " nodes in total." << endl;
}


/***********************************************************/
/***************  FUNCTIONS TO BE COMPLETED  ****************/
/***********************************************************/

/////////////////////////////////////////////////////////////
/////////////////////  ADD FUNCTIONS ////////////////////////
/////////////////////////////////////////////////////////////

unsigned int SkipList::randHeight() {
    ////////////// Write your code below  ////////////////////////
    //srand(time(0));
    //cout << RAND_MAX << endl;
    /*unsigned int t = 1+rand();
    //cout << t << " =t" << endl;
    if (t == RAND_MAX) {
        t--;
    }
    unsigned int j = 2;
    unsigned randomHeight = 1;
    for (unsigned int i = 1; i <= m_maxHeight-1; i++) {
        if (t > RAND_MAX/j) {
            break;
        }
        j+= j;
        randomHeight++;
    }*/

    int flipCoinRandom;
    unsigned int height;
    //srand(time(NULL));
    for (height = 1; height < m_maxHeight ; height++){
      flipCoinRandom = rand() % 2;
      if (flipCoinRandom == 0) return height;
    }
    return height; //you have to replace this line with your own.*/


    //return randomHeight; //you have to replace this line with your own.
}


int SkipList::add(SkipListNode* target, SkipListNode* newNode,
                  unsigned level) {
    if (target->nextAtLevel(level) != NULL &&
            *target->nextAtLevel(level) < *newNode) {
        countAdd++;
    }
    ////////////// Write your code below  ////////////////////////

    /*Key testKey ("B");
    SkipListNode* testB = new SkipListNode(testKey, 5);
    for (int i = target->height() - 1; i >=0; i--) {   // use level
        //cout << *target << endl;
        //cout << target->height() << endl;
        //cout << i << endl;
        while (target->nextAtLevel(i) != NULL 
            && *testB > *target->nextAtLevel(i)) {
            cout << "current->next : ";
            cout << *target << "->" << *target->nextAtLevel(i) << endl; 
            target = target->nextAtLevel(i);
        }
        if (i < testB->height()) {
            testB->setNextAtLevel(i, target->nextAtLevel(i));
            target->setNextAtLevel(i, testB);
        }
    }*/

    for (int i = target->height() - 1; i >=0; i--) {   // use level
        while (target->nextAtLevel(i) != NULL 
            && *newNode > *target->nextAtLevel(i)) {
            target = target->nextAtLevel(i);
        }
        if (i < newNode->height()) {
            newNode->setNextAtLevel(i, target->nextAtLevel(i));
            target->setNextAtLevel(i, newNode);
        }
    }


    return 1;
    //return 0;  //you have to replace this line with your own.
}

/////////////////////////////////////////////////////////////
/////////////////////  FIND FUNCTION ////////////////////////
/////////////////////////////////////////////////////////////
SkipListNode* SkipList::find(SkipListNode* target, const Key& key,
                             unsigned level) {
    if (target->nextAtLevel(level) != NULL &&
            *target->nextAtLevel(level) < key) {
        countFind++;
    }
    ////////////// Write your code below  ////////////////////////
    for (int i = target->height() - 1; i >= 0; i--) {
        while (target->nextAtLevel(i) != NULL 
            && key > *target->nextAtLevel(i)) {
            target = target->nextAtLevel(i);
        }
    }

    if (target->nextAtLevel(0) != NULL 
        && *target->nextAtLevel(0) == key) {
        return target->nextAtLevel(0);
    } else {
        return NULL;
    }
}


/////////////////////////////////////////////////////////////
/////////////////////  DEL FUNCTION ////////////////////////
/////////////////////////////////////////////////////////////
SkipListNode* SkipList::del(SkipListNode* target, const Key& key,
                            unsigned level) {
    if (target->nextAtLevel(level) != NULL &&
            *target->nextAtLevel(level) < key) {
        countDelete++;
    }
    ////////////// Write your code below  ////////////////////////
    SkipListNode* linker = NULL;
    int currentLevel = target->height() - 1;  //use level


    while (target != NULL && currentLevel >= 0) { 
        while (target->nextAtLevel(currentLevel) != NULL 
            && key > *target->nextAtLevel(currentLevel)) {
            target = target->nextAtLevel(currentLevel);
            
        }
        if (target->nextAtLevel(currentLevel) != NULL 
            && key == *target->nextAtLevel(currentLevel)) {
            linker = target->nextAtLevel(currentLevel);
            target->setNextAtLevel(currentLevel, linker->nextAtLevel(currentLevel));
        }

        currentLevel--;
    }

    return linker; ///you have to replace this line with your own.
}













