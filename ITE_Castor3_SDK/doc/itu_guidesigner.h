/** @page itu_guidesigner GUI Designer
@section itu_guidesigner_overview Overview
@par Introduction
- ITU Library
  <ol>
    <li>A UI library running on ITE Castor3 platform.
    <li>Widget/scene tree based architecture.
    <li>Written in C.
    <li>Custom UI data format.
  </ol>

- GUI Designer
  <ol>
    <li>A UI Editor tool running on WIN32 platform.
    <li>To generate UI layout data for ITU library.
    <li>UI layout data embedded raw bitmap data.
    <li>Support Emulator.
  </ol>

@par ITU Library Features
- Fast Loading
  <ol>
    <li>The data layout in file is the same as in memory.
    <li>Just call fread() once to read all UI data.
    <li>Support HW decompress UI data file.
  </ol>

- Fast drawing
  <ol>
    <li>Only drawing on content is changed
  </ol>

- Support multi-languages
  <ol>
    <li>Up to 8 multi-languages
  </ol>

- Use FreeType as Text renderer
  <ol>
    <li>Support font cache
  </ol>

- Support Multiple Renderers
  <ol>
    <li>Software
    <li>STN LCD
    <li>M2D (HW)
  </ol>

- Support Transition Effects
  <ol>
    <li>Fade In/Out
    <li>Scroll Left/Up/Right/Down
  </ol>

- Support Screen Rotation
  <ol>
    <li>90 degree
    <li>180 degree
    <li>270 degree
  </ol>

- Support multiple input devices
  <ol>
    <li>Keyboard
    <li>Mouse
    <li>Touch panel with Gesture events
  </ol>

@par Widgets
- Widget, Layer, Background
- Icon
- Text, TextBox, ScrollText
- BorderWindow, FlowWindow
- Button, CheckBox, RadioBox, PopupButton
- ListBox, FileListBox, IconListBox, MediaFileListBox
- Sprite, SpriteButton
- ProgressBar, TrackBar, CircleProgressBar, ScrollBar
- Keyboard
- DigitalClock, AnalogClock
- Calendar
- Animation, Wheel, CoverFlow

@par Actions
- Internal default behaviors defined by ITU library
  <ol>
    <li>Triggered by events
  </ol>
- Event : event to trigger
- Target : All widgets or function
- Action
  <ol>
    <li>Show, Hide : All widgets
    <li>Focus : Buttons, TextBox
    <li>Prev, Next, Back : ListBoxs
    <li>Play, Stop, Goto : Sprite, Animation
    <li>Language : Texts
    <li>Input : TextBox, Keyboard
    <li>Bind : Keyboard
    <li>Clear : TextBox
    <li>Enable, Disable : All widgets
    <li>Check, UnCheck : CheckBox, RadioBox, ListBox
    <li>Function : Callback function
    <li>Reload : ListBox, ScrollBar
  </ol>
- Parameter : Max 32-byte characters

@par GUI Designer Features
- Load/Save .xml
- Export .itu file
- Support compress .itu file
- Multiple Layers
- Undo/Redo
- Emulator

@par System Architecture of ITU Library
- Use Case
  <ol>
    <li>Artist uses GUI Designer to design UI and export .itu file
    <li>RD uses ITU library to load/draw .itu file, and adds custom functions to specified widgets
  </ol>
  @image html UseCase.jpg

- Main package
  <ol>
    <li>SceneSystem : The ITU scene system to load/update/draw scene
    <li>FreeTypeSystem : The font system to load/draw fonts
    <li>ITC : The ITU Common Library for general functions like tree and stream.
    <li>DecompressSystem : HW or SW decompress .itu file
    <li>RendererSystem : draw bitmap to screen
  </ol>
  @image html ClassMain.jpg

- Runtime flow
  <ol>
    <li>Initializes specified renderer.
    <li>Initializes FreeType library.
    <li>Loads specified font file.
    <li>Initializes the scene.
    <li>Loads .itu file.
    <li>Gets events from input device(s).
    <li>Updates the scene by input/timer events.
    <li>Draws the scene, ITU will draw it by renderer/freetype's functions.
    <li>Flip screen.
  </ol>
  @image html SequenceMain.jpg

- Widget classes hierarchy
  <ol>
    <li>The scene is composed by widget tree.
    <li>Every widget can be inherited to extend another widget.
    <li>Extended widget can overwrite parent's functions if neccssary.
  </ol>
  @image html SceneWidget.jpg

- Modules for loading scene file
  <ol>
    <li>ITU use ITC Stream library to load .itu file or embedded itu array.
    <li>ITU decompress .itu file by HW DCPS module or SW libucl.
  </ol>
  @image html SceneLoad.jpg

- Renderer system
  <ol>
    <li>Every renderer implementation need to implement renderer interface.
  </ol>
  @image html Renderer.jpg

- Effect system
  <ol>
    <li>Every effect can be inherited to extend another effect.
  </ol>
  @image html SceneEffect.jpg

@section itu_guidesigner_release_note Release Notes
- Version 1.0.6604, 2018/01/30
  <ol>
	<li>Add change resolution function on Edit menu.
	<li>Add SimpleAnimation widget.
	<li>Add Arabic text support.
  </ol>
- Version 1.0.6569, 2017/12/26
  <ol>
	<li>Support to execute GUIDesigner by xml file double click.
	<li>Expand multi-language count to 32.
	<li>Support motion blur property on animation widget.
	<li>Do dither function on JPEG compression.
	<li>Avoid exporting duplicate images.
    <li>Add Slidable/DragChangeFactor/MouseUpChangeFactor for Wheel.
	<li>Add EyeMotion/MinChangeFactor for Coverflow.
	<li>Add WaveBackground widget.
	<li>Fix cannot setting ItemHeight property of ScrollMediaFileListBox bug.
	<li>Add Clipper widget.
	<li>Add HideDelay property to Layer widget.
    <li>PreAdd StepWheel widget architecture.
    <li>Add Delay property to TrackBar and Meter widgets.
  </ol>
- Version 1.0.6438, 2017/08/17
  <ol>
	<li>Add all Widgets' other column's description in Traditional/Simplified Chinese.
	<li>Add Alpha property to Background widget.
	<li>Add OriginalSize property to Background widget.
	<li>Disable RGB565A8 pixelformat.
	<li>Add Copy action function.
  </ol>
- Version 1.0.6410, 2017/07/20
  <ol>
    <li>Separate out itu.dll
    <li>Add Build option to invoke Kconfig building tool.
    <li>Add TextAlign option to TextBox widget.
    <li>Add Angle option to Container widget.
  </ol>    
- Version 1.0.6374, 2017/06/14
  <ol>
    <li>Add Bold and BoldSize properties to text related widgets.
    <li>Add LoadFont action.
    <li>Add slide events to scalecoverflow widget.
    <li>Add ColonTarget property to DigitalClock widget.
    <li>Disable auto size mode on Icon widget.
  </ol>
- Version 1.0.6334, 2017/05/05
  <ol>
    <li>Add DrawPen widget.
    <li>Fix text not align on middle-center on Button/CheckBox/RadioBox/PopupButton/PopupRadioBox widgets bug.
    <li>Fix text size incorrect bug.
    <li>Add MinRadius property to Meter widget.
    <li>Add MoveType property to Animation widget.
    <li>Add Set0~7 actions for variable mechanism.
    <li>Add FontSquare property to Wheel widget.
    <li>Increase undo items to 100.
    <li>Add x64 version.
    <li>Add CutByRectangle property to icon widget.
    <li>Add slide events to coverflow widget.
    <li>Add Jumpable property to trackbar widget.
    <li>Add LoadExternal/ReleaseExternal actions.
  </ol>
- Version 1.0.6219, 2017/01/10
  <ol>
    <li>Add drag support for FOLD effect of PageFlow.
  </ol>
- Version 1.0.6207, 2016/12/29
  <ol>
    <li>Add ratio control for FLIP2 effect of PageFlow.
    <li>Fix cannot adjust ItemHeight property of FileListBox/MediaFileListBox widgets.
  </ol>
- Version 1.0.6200, 2016/12/22
  <ol>
    <li>Change behavior of ScaleCoverFlow widget.
    <li>Add WheelBackground widget.
  </ol>
- Version 1.0.6198, 2016/12/20
  <ol>
    <li>Add DragIcon widget to use it as Joystick (with animation effect).
    <li>Add FilePath property to icon widget.
    <li>Add Blur widget.
    <li>Added some special flaqs for button usage.
    <li>Add ScaleCoverFlow widget.
    <li>Add Volume property to Video widget.
  </ol>
- Version 1.0.6141, 2016/10/24
  <ol>
    <li>Add TransformType/TransformX/TransformY properties to icon/background/button/checkbox/radiobox widgets.
    <li>Add TransformAnimation property to animation widget.
    <li>Add Stretch and Angle properties to background widget.
    <li>Add slideshow widget.
    <li>Modify Wheel architecture.
  </ol>
- Version 1.0.6117, 2016/09/30
  <ol>
    <li>CoverFlow add BoundaryAlign and SlideMaxCount under non-cycle-mode.
    <li>Add JPEG Quality option to adjust JPEG compression ratio.
    <li>Sync ImageCoverFlow variables with CoverFlow.
    <li>Add FitToRectangle property to icon widget.
    <li>Add Dragging event to button widget.
  </ol>
- Version 1.0.6092, 2016/09/05
  <ol>
    <li>Add fontWidth to all text object/define.
    <li>Add New Template project function.
  </ol>
- Version 1.0.6081, 2016/08/23
  <ol>
    <li>Add Speed and SlideCount for wheel.
    <li>Add Custom event for wheel to sent after mouseup when wheel idle.
  </ol>
- Version 1.0.6078, 2016/08/22
  <ol>
    <li>Fix error StringSet when object too much (get same hash key)
    <li>Change default function table file name from "file_table.c" to "function_table.c"
    <li>Auto generate CFileName of Layer widget when it is empty.
    <li>Add search widget dialog.
    <li>Add duplicate names dialog.
    <li>Filter events by widget type on ActonXX options.
    <li>Add "Create Layer CMake..." option on "File" menu.
    <li>Change "Bring to Front" and "Send to Back" options to "Move Bottom" and "Move Top" options on tree menu.
    <li>Add Wipe effects.
    <li>Add BackgroundImage and BarImage properties to ProgressBar widget.
    <li>Fix the wrong stringset array for same number string in multilang.
    <li>Add TransferAlpha property to Background and BackgroundButton widgets.
  </ol>
- Version 1.0.6060, 2016/08/04
  <ol>
    <li>Add menu options to Tree panel.
    <li>Auto exporting .itu on running emulator.
    <li>Filter targets by action on ActonXX options.
  </ol>
- Version 1.0.6053, 2016/07/28
  <ol>
    <li>Add EffectRatio variable to PageFlow Widget in GUIDesigner. EffectRatio value could be 1~4.
    <li>Fix TableIconListBox bind function with TableListBox.
    <li>Add AlwaysVisible variable to Background and Container in GUIDesigner.
    <li>Add FontIndex property to widgets which contain text.
    <li>Set default font path as "./WenQuanYiMicroHeiMono.ttf" and "../../data/font/WenQuanYiMicroHeiMono.ttf".
    <li>Add Audio widget.
    <li>Add BounceRatio property to CoverFlow widget.
    <li>Add "Create Function Table..." option on "File" menu.
    <li>Add "Create Layer Code..." option on "File" menu.
    <li>Add "Project Directory..." option on "Option" menu.
    <li>Add generating action function to layer c code function.
    <li>Add tool bar.
    <li>Add drag & drop function to Tree tab.
    <li>Backup previous file on saving XML and create layer code.
  </ol>    
- Version 1.0.6024, 2016/06/29
  <ol>
    <li>Add TableIconListBox Widget.
    <li>Add Touchable property to ImageCoverFlow widget.
    <li>Add EnableAllItems property to CoverFlow/ImageCoverFlow widgets.
    <li>Support white space text on Text widget.
  </ol>    
- Version 1.0.6019, 2016/06/24
  <ol>
    <li>Add AxisShift to PageFlow widget. AxisShift is Pixel value and only available for Flip effect now. The maximum AxisShift is 80% of PageFlow Widget width/2. For example, PageFlow width 200, AxisShift range is -80 ~ 80 pixel.
    <li>"Bring to Front" and "Send to Back" menu function can adjust the tree position of widget.
  </ol>    
- Version 1.0.6015, 2016/06/20
  <ol>
    <li>Add orientiation to PageFlow widget.
    <li>Do not clip text on wheel widget.
  </ol>    
- Version 1.0.6010, 2016/06/15
  <ol>
    <li>Add Layout, Draggable and Gap options to Container widget.
    <li>Fix widget order on Tree page incorrect bug.
    <li>Add Touchable property to Wheel/CoverFlow/PageFlow widgets.
    <li>Add import sprite images function to SpriteButton widget.
  </ol>    
- Version 1.0.9.18562, 2016/05/26
  <ol>
    <li>Add Delay0~Delay7 events and DoDelay0~DoDelay7 action commands.
    <li>Show cursor position on left-bottom corner.
    <li>Prompt save file on exit.
    <li>Add EffectSteps, ShowDelay, HideDelay properties to Container/Background/BackgroundButton widgets.
    <li>Add Stopped event for Animation/Sprite widgets.
    <li>Add Shadow widget.
    <li>Add ExternalImage option to Icon/Background widgets.
    <li>Add WeekTarget option to DigitalClock widget.
  </ol>    
- Version 1.0.8.31470, 2016/05/03
  <ol>
    <li>Add External option to widgets with images.
    <li>Add import sprite images option to Edit menu.
    <li>Add Enable/Disable External options to Layer menu.
    <li>Add page flow widget.
    <li>Add FocusFontColor and ReadFontColor properties to list box related widgets.
    <li>Add FocusImage properties to icon list box and scroll icon list box widgets.
    <li>Add CheckedFontColor property to check box/radio box/popup radio box widgets.
    <li>Fix possible static text incorrect bug.
    <li>Add RGB565A8 pixel format.
    <li>Add MaxValue property to CircleProgressBar and Meter widgets.
    <li>Add FocusFontHeight property on Wheel widget, for non-Draggable mode only.
    <li>Change default value of BorderSize of buttons to 1.
    <li>Add AlwaysVisible option to animation widget.
  </ol>
- Version 1.0.7.25797, 2016/03/21
  <ol>
    <li>Add ripple background widget.
    <li>Fix cannot delete image on icon widget bug.
    <li>Add Alpha property to icon widget.
    <li>Add curve widget.
    <li>Add table list box widget.
    <li>Fix cannot set ItemHeight on scroll icon list box and icon list box widgets bug.
    <li>Add popup radio box widget.
    <li>Add tree view pane.
    <li>Add hided property to all widgets for design-time behavior.
    <li>Fix cannot copy/paste/undo actions bug.
    <li>Add AlwaysVisible option to layer widget.
    <li>Add language sprite widget.
    <li>Support multi-language on wheel widget.
    <li>Replace SupportTouch option by Gap option on track bar widget.
  </ol>
- Version 1.0.6.17410, 2016/01/14
  <ol>
    <li>Add scroll media file list box widget.
    <li>Implement repeat and random modes on media file list box widget.
    <li>Change default maximum value of track bar widget from 10 to 100.
    <li>Add mouse double-click event.
    <li>Add gradient fill support on progress bar widget.
    <li>Fix Layers not sync when layer is removed.
    <li>Add meter widget.
    <li>Add color/move/rotate/scale/scale on center options on animation widget.
    <li>Add angle option to icon/button/check box/radio box widgets.
    <li>Add ResponseToUpKey option on popuop button widget.
    <li>Add scroll icon list box widget.
    <li>Add export images function.
    <li>Add video widget.
    <li>Add draggable option to scroll list box/scroll icon list box/scroll media file list box/scroll bar widgets.
    <li>Add tracker, touch and tip options to track bar widget.
    <li>Add orientation option to cover flow widget.
    <li>Add color picker widget.
    <li>Add image cover flow widget.
    <li>Change default colors and border size of button widgets.
    <li>Add background button widget with mouse down/up outside events.
    <li>Add maximum, minimum, step value target options to progress bar widget.
    <li>Add support touch option to check box widget.
    <li>Remove support touch and action options from circle progress bar and progress bar widgets.
    <li>Add enabled option to container/background widgets.
    <li>Add JPEG Compression option.
    <li>Add Cycling option to animation widget.
    <li>Change image count of icon list box/scroll icon list box to 16.
    <li>Add HasLongPress option to coverflow/icon list box/scroll icon list box widgets.
    <li>Add PreDraw option to layer widget.
  </ol>
- Version 1.0.5.27740, 2015/9/21
  <ol>
    <li>Add start & end angle parameter to circle progress bar widget.
    <li>Support touch on circle progress bar widget.
  </ol>
- Version 1.0.4.21235, 2015/9/14
  <ol>
    <li>Fix new document will save to old document bug.
    <li>Add Progress option to Sprite Widget to simplify progress bar design.
    <li>Fix possible compress will hang bug.
  </ol>
- Version 1.0.3.27348, 2015/8/10
  <ol>
    <li>Add response to up key flag to check box and radio box widgets.
  </ol>
- Version 1.0.2.27619, 2015/8/5
  <ol>
    <li>Add scroll listbox widget.
    <li>Fix renaming layer won't update layer list bug.
  </ol>
- Version 1.0.1.24744, 2015/7/30
  <ol>
    <li>Adjust toolbox/designer/property panels layout.
    <li>Modify font type and size of toolbox, layers, widgets and property.
  </ol>
- Version 1.0.1.26321, 2015/7/24
  <ol>
    <li>Add Layers page to show all layers.
    <li>Add Widgets page to show all widgets of current layer.
    <li>Add MouseLongPress event.
  </ol>
- Version 1.0.0.30261, 2015/7/13
  <ol>
    <li>Add popup button widget.
    <li>Add version information on about page.
  </ol>

*/
