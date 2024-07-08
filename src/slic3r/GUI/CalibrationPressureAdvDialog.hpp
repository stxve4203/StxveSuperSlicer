#ifndef slic3r_GUI_CalibrationPressureAdvDialog_hpp_
#define slic3r_GUI_CalibrationPressureAdvDialog_hpp_

#include "CalibrationAbstractDialog.hpp"
//pressure advance PressureAdv
namespace Slic3r { 
namespace GUI {

class CalibrationPressureAdvDialog : public CalibrationAbstractDialog
{

public:
    CalibrationPressureAdvDialog(GUI_App* app, MainFrame* mainframe) : CalibrationAbstractDialog(app, mainframe, "Pressure calibration") 
    { create(boost::filesystem::path("calibration") / "filament_pressure", "filament_pressure.html", wxSize(1600, 600)); Centre(wxBOTH); currentTestCount = 1; }
    virtual ~CalibrationPressureAdvDialog(){ }

    
protected:
    void create_buttons(wxStdDialogButtonSizer* sizer) override;
    void create_row_controls(wxBoxSizer* parent_sizer, int row_count);
    void create_geometry(wxCommandEvent& event_args);
    void on_row_change(wxCommandEvent& event);
    double calc_PA_values(double, double, double);
    double magical_scaling(double, double, double, double, double, double, double );

    //i've set choice boxes for now just to save me typing numbers in when i want to test it :)
    wxComboBox* nbRuns;

    std::vector<wxComboBox*> dynamicFirstPa;      //first layer PA -user manual entry
    std::vector<wxComboBox*> dynamicStartPa;      //starting PA value -user manual entry
    std::vector<wxComboBox*> dynamicEndPa;        //ending PA value -user manual entry
    std::vector<wxComboBox*> dynamicPaIncrement;  //increment PA by this value -user manual entry~~ or have drop down box ?
    std::vector<wxComboBox*> dynamicExtrusionRole;//extrusion role Pressure/Linear Advance -user choice select
    std::vector<wxCheckBox*> dynamicEnableST;     // checkbox for "smooth_time" - klipper only feature?
    std::vector<wxBoxSizer*> dynamicRowcount;     // To keep track of dynamically created rows

    wxBoxSizer* dynamicSizer;
    int currentTestCount;
};

} // namespace GUI
} // namespace Slic3r

#endif
