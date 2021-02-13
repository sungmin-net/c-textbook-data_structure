#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "908p_avllinkedstack.h"

#include "906p_avldef.h"

LinkedStack* createLinkedStack() {
    LinkedStack* pReturn = NULL;
    pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedStack));
    } else {
        printf("Error, malloc(), createLinkedStack()\n");
        return NULL;
    }
    return pReturn;
}

int pushLinkedStack(LinkedStack* pStack, StackNode element) {
    int ret = FALSE;
    StackNode* pNode = NULL;

    if (pStack != NULL) {
        pNode = (StackNode*)malloc(sizeof(StackNode));
        if (pNode != NULL) {
            memset(pNode, 0, sizeof(StackNode));
            *pNode = element;
            pNode->pLink = pStack->pTopElement;
            pStack->pTopElement = pNode;
            pStack->currentElementCount++;
            ret = TRUE;
        } else {
            printf("Error, malloc(), pushLinkedStack()\n");
        }
    }
    return ret;
}

StackNode* popLinkedStack(LinkedStack* pStack) {
    StackNode* pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == FALSE) {
            pReturn = pStack->pTopElement;
            pStack->pTopElement = pReturn->pLink;
            pReturn->pLink = NULL;
            pStack->currentElementCount--;
        }
    }
    return pReturn;
}

StackNode* peekLinkedStack(LinkedStack* pStack) {
    StackNode* pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == FALSE) {
            pReturn = pStack->pTopElement;
        }
    }
    return pReturn;
}

void deleteLinkedStack(LinkedStack* pStack) {
    StackNode* pNode = NULL;
    StackNode* pDelNode = NULL;

    if (pStack != NULL) {
        pNode = pStack->pTopElement;
        while (pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pLink;
            free(pDelNode);
        }
        free(pStack);
    }
}

int isLinkedStackFull(LinkedStack* pStack) {
    return FALSE;
}

int isLinkedStackEmpty(LinkedStack* pStack) {
    int ret = FALSE;
    if (pStack != NULL) {
        if (pStack->currentElementCount == 0) {
            ret = TRUE;
        }
    }
    return ret;
}

