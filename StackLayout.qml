import QtQuick 2.5
import QtQuick.Layouts 1.3


StackLayout {
    id: layout
    currentIndex: 0

    GridLayout { // simple mode layout
        id: gridSimple
        columns: 5
        rows: 5
        columnSpacing: 0
        rowSpacing: 0

        signal buttonPressed

        Button { text: "\u232B";  operator: true; Layout.row: 0; Layout.column: 3 } // "<"
        Button { text: "C";  operator: true; Layout.row: 0; Layout.column: 4 }

        Button { text: "7" }
        Button { text: "8" }
        Button { text: "9" }
        Button { text: "÷"; operator: true; dimmable: true }
        Button { text: "√"; operator: true; dimmable: true }

        Button { text: "4" }
        Button { text: "5" }
        Button { text: "6" }
        Button { text: "×"; operator: true; dimmable: true }
        Button { text: "\u00B9\u0337\u2093"; operator: true; dimmable: true } // "1/x"

        Button { text: "1" }
        Button { text: "2" }
        Button { text: "3" }
        Button { text: "−"; operator: true; dimmable: true }

        Button { text: "="; operator: true; dimmable: true; Layout.row: 3; Layout.column: 4; Layout.fillHeight: true; Layout.rowSpan: 2 }

        Button { text: "0"; Layout.row: 4; Layout.column: 0; Layout.fillWidth: true; Layout.columnSpan: 2 }
        Button { text: "."; dimmable: true }
        Button { text: "+"; operator: true; dimmable: true }
    }

    GridLayout { // compl mode layout
        id: gridCompl
        columns: 9
        rows: 5
        columnSpacing: 0
        rowSpacing: 0

        signal buttonPressed

        Button { text: "\u232B";  operator: true; Layout.row: 0; Layout.column: 5; Layout.columnSpan: 2; Layout.fillWidth: true } // "<"
        Button { text: "C";  operator: true; Layout.row: 0; Layout.column: 7; Layout.columnSpan: 2; Layout.fillWidth: true }

        Button { text: "sh"; operator: true; dimmable: true }
        Button { text: "sin"; operator: true; dimmable: true }
        Button { text: "e\u207F"; operator: true; dimmable: true } // "e^n"
        Button { text: "x\u00B2"; operator: true; dimmable: true } // "x^2"
        Button { text: "7" }
        Button { text: "8" }
        Button { text: "9" }
        Button { text: "÷"; operator: true; dimmable: true }
        Button { text: "√"; operator: true; dimmable: true }

        Button { text: "ch"; operator: true; dimmable: true }
        Button { text: "cos"; operator: true; dimmable: true }
        Button { text: "ln"; operator: true; dimmable: true }
        Button { text: "x\u00B3"; operator: true; dimmable: true } // "x^3"
        Button { text: "4" }
        Button { text: "5" }
        Button { text: "6" }
        Button { text: "×"; operator: true; dimmable: true }
        Button { text: "\u00B9\u0337\u2093"; operator: true; dimmable: true } // "1/x"

        Button { text: "th"; operator: true; dimmable: true }
        Button { text: "tan"; operator: true; dimmable: true }
        Button { text: "log"; operator: true; dimmable: true }
        Button { text: "x\u207F"; operator: true; dimmable: true } // "x^n"
        Button { text: "1" }
        Button { text: "2" }
        Button { text: "3" }
        Button { text: "−"; operator: true; dimmable: true }

        Button { text: "="; operator: true; dimmable: true; Layout.row: 3; Layout.column: 8; Layout.fillHeight: true; Layout.rowSpan: 2 }

        Button { text: "n!"; operator: true; dimmable: true }
        Button { text: "\u03C0"; operator: true; dimmable: true } // "pi"
        Button { text: "\u00B3\u221A"; operator: true; dimmable: true } // "3√"
        Button { text: "\u207F\u221A"; operator: true; dimmable: true } // "n√"
        Button { text: "0"; Layout.row: 4; Layout.column: 4; Layout.fillWidth: true; Layout.columnSpan: 2 }
        Button { text: "."; dimmable: true }
        Button { text: "+"; operator: true; dimmable: true }
    }
}

