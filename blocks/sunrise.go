package main

import "C"

import (
	"fmt"
	"time"
	"github.com/kelvins/sunrisesunset"
)

func getSunriseSunset(latitude, longitude float64) (string, error) {
	now := time.Now()
	_, offset := now.Zone()
	p := sunrisesunset.Parameters{
		Latitude: latitude,
		Longitude: longitude,
		UtcOffset: float64(offset) / 60.0 / 60.0,
		Date: now.UTC(),
	}

	sunrise, sunset, err := p.GetSunriseSunset()
	if err != nil {
		return "", err
	}

	return fmt.Sprintf("🌅 %s | 🌇 %s", sunrise.Format("15:04"), sunset.Format("15:04")), nil
}

//export GetSunriseSunset
func GetSunriseSunset(latitude, longitude float64) *C.char {
	str, err := getSunriseSunset(latitude, longitude)
	if err != nil {
		return nil
	}
	return C.CString(str)
}

func main() {}
