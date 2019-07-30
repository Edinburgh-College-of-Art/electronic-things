let state = false
let samples = 0
let sensing = false
let reading = 0
let calibration_value = 0
let threshold = 0
let index = 0
input.onButtonPressed(Button.A, () => {
    calibration_value = 0
    calibrate()
    basic.showNumber(calibration_value)
})
function calibrate()  {
    reading = 0
    for (let index = 0; index <= samples; index++) {
        readPin()
        basic.pause(1)
    }
    calibration_value = reading / samples
}
function readPin()  {
    reading += pins.analogReadPin(AnalogPin.P0)
    pins.digitalWritePin(DigitalPin.P0, 1)
}
function sense()  {
    reading = 0
    for (let index = 0; index <= samples; index++) {
        readPin()
        basic.pause(1)
    }
    state = calibration_value + threshold < reading / samples
}
input.onButtonPressed(Button.B, () => {
    sensing = true
    while (sensing) {
        sense()
        if (state) {
            basic.showLeds(`
                # # # # #
                # # # # #
                # # # # #
                # # # # #
                # # # # #
                `)
        } else {
            basic.showLeds(`
                . . . . .
                . . . . .
                . . # . .
                . . . . .
                . . . . .
                `)
        }
        basic.pause(10)
    }
})
threshold = 2
pins.setPull(DigitalPin.P0, PinPullMode.PullNone)
samples = 8
state = false
