#include <stdio.h>
#include <stdlib.h>
#include "678p_graphlinkedlist.h"
#include "679p_linkedgraph.h"
#include "678p_grapharrayheap.h"
#include "680p_graphmst.h"

int main(int argc, char* argv[]) {
    int i = 0;
    LinkedGraph* pG1 = NULL;
    LinkedGraph* pMST1 = NULL;

    // 그래프 생성
    pG1 = createLinkedGraph(6);
    if (pG1 != NULL) {
        // 그래프 초기화, 노드추가
        for (i = 0 ; i < 6 ; i++) {
            addVertexLinkedGraph(pG1, i);
        }

        // 그래프 초기화, 간선추가
        addEdgeWithWeightLinkedGraph(pG1, 0, 1, 4);
        addEdgeWithWeightLinkedGraph(pG1, 0, 2, 3);
        addEdgeWithWeightLinkedGraph(pG1, 1, 2, 2);
        addEdgeWithWeightLinkedGraph(pG1, 2, 3, 1);
        addEdgeWithWeightLinkedGraph(pG1, 3, 4, 1);
        addEdgeWithWeightLinkedGraph(pG1, 3, 5, 5);
        addEdgeWithWeightLinkedGraph(pG1, 4, 5, 6);

        printf("G1:\n");
        displayLinkedGraph(pG1);

        // Kruskal 알고리즘으로 MST 생성
        printf("\nKruskal MST:\n");
        pMST1 = mstKruskal(pG1);
        displayLinkedGraph(pMST1);

        // 그래프삭제
        deleteLinkedGraph(pG1);
        deleteLinkedGraph(pMST1);
    }
    return 0;
}
