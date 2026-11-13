//
//  TBSDKStockPositionSharePieRenderer.swift
//  TBTradeBusiness
//
//  Created by F.S. on 2023/5/10.
//

import UIKit
import ChartKLineView

public class TBSDKStockPositionSharePieRenderer: PieChartRenderer {

    public override func drawValues(context: CGContext)
    {
        guard
            let chart = chart,
            let data = chart.data
            else { return }
        
        let center = chart.centerCircleBox
        
        // get whole the radius
        let radius = chart.radius
        let rotationAngle = chart.rotationAngle
        let drawAngles = chart.drawAngles
        let absoluteAngles = chart.absoluteAngles
        
        let phaseX = animator.phaseX
        let phaseY = animator.phaseY
        
        var labelRadiusOffset = radius / 10.0 * 3.0
        
        if chart.drawHoleEnabled
        {
            labelRadiusOffset = (radius - (radius * chart.holeRadiusPercent)) / 2.0
        }
        
        let labelRadius = radius - labelRadiusOffset
        
        let dataSets = data.dataSets
        
        let yValueSum = (data as! PieChartData).yValueSum
        
        let drawEntryLabels = chart.isDrawEntryLabelsEnabled
        let usePercentValuesEnabled = chart.usePercentValuesEnabled
//        let entryLabelColor = chart.entryLabelColor
//        let entryLabelFont = chart.entryLabelFont
        
        var angle: CGFloat = 0.0
        var xIndex = 0
        
        context.saveGState()
        defer { context.restoreGState() }
        
        for i in 0 ..< dataSets.count
        {
            guard let dataSet = dataSets[i] as? PieChartDataSetProtocol else { continue }
            
            let drawValues = dataSet.isDrawValuesEnabled
            
            if !drawValues && !drawEntryLabels && !dataSet.isDrawIconsEnabled
            {
                continue
            }
            
            let iconsOffset = dataSet.iconsOffset
            
            let xValuePosition = dataSet.xValuePosition
            let yValuePosition = dataSet.yValuePosition
            
            let valueFont = dataSet.valueFont
            let entryLabelFont = dataSet.entryLabelFont
            let lineHeight = valueFont.lineHeight
            
            let formatter = dataSet.valueFormatter
            var prePoint = CGPoint.zero
            
            for j in 0 ..< dataSet.entryCount
            {
                guard let e = dataSet.entryForIndex(j) else { continue }
                let pe = e as? PieChartDataEntry
                
                if xIndex == 0
                {
                    angle = 0.0
                }
                else
                {
                    angle = absoluteAngles[xIndex - 1] * CGFloat(phaseX)
                }
                
                let sliceAngle = drawAngles[xIndex]
                let sliceSpace = getSliceSpace(dataSet: dataSet)
                let sliceSpaceMiddleAngle = sliceSpace / labelRadius.DEG2RAD
                //设置线的颜色和饼状图颜色一致
                dataSet.valueLineColor = dataSet.colors[j]
                
                // offset needed to center the drawn text in the slice
                let angleOffset = (sliceAngle - sliceSpaceMiddleAngle / 2.0) / 2.0
                
                angle = angle + angleOffset
                
                let transformedAngle = rotationAngle + angle * CGFloat(phaseY)
                
                let value = usePercentValuesEnabled ? e.y / yValueSum * 100.0 : e.y
                let valueText = formatter.stringForValue(
                    value,
                    entry: e,
                    dataSetIndex: i,
                    viewPortHandler: viewPortHandler)
                
                let sliceXBase = cos(transformedAngle.DEG2RAD)
                let sliceYBase = sin(transformedAngle.DEG2RAD)
                
                let drawXOutside = drawEntryLabels && xValuePosition == .outsideSlice
                let drawYOutside = drawValues && yValuePosition == .outsideSlice
                let drawXInside = drawEntryLabels && xValuePosition == .insideSlice
                let drawYInside = drawValues && yValuePosition == .insideSlice
                
                let valueTextColor = dataSet.valueTextColorAt(j)
                let entryLabelColor = dataSet.entryLabelColor
                
                if drawXOutside || drawYOutside
                {
                    let valueLineLength1 = dataSet.valueLinePart1Length
//                    let valueLineLength2 = dataSet.valueLinePart2Length
                    let valueLinePart1OffsetPercentage = dataSet.valueLinePart1OffsetPercentage
                    
                    var pt2: CGPoint
                    var labelPoint: CGPoint
                    var align: NSTextAlignment
                    
                    var line1Radius: CGFloat
                    
//                    var rect = CGRect()
                    
                    if chart.drawHoleEnabled
                    {
                        line1Radius = (radius - (radius * chart.holeRadiusPercent)) * valueLinePart1OffsetPercentage + (radius * chart.holeRadiusPercent)
                    }
                    else
                    {
                        line1Radius = radius * valueLinePart1OffsetPercentage
                    }
                    
//                    let polyline2Length = dataSet.valueLineVariableLength
//                        ? labelRadius * valueLineLength2 * abs(sin(transformedAngle.DEG2RAD))
//                        : labelRadius * valueLineLength2
                    
                    let pt0 = CGPoint(
                        x: line1Radius * sliceXBase + center.x,
                        y: line1Radius * sliceYBase + center.y)
                    
                    let pt1 = CGPoint(
                        x: labelRadius * (1 + valueLineLength1) * sliceXBase + center.x,
                        y: labelRadius * (1 + valueLineLength1) * sliceYBase + center.y)
                    
                    if transformedAngle.truncatingRemainder(dividingBy: 360.0) >= 90.0 && transformedAngle.truncatingRemainder(dividingBy: 360.0) <= 270.0
                    {
                        pt2 = CGPoint(x: center.x - radius * 1.5, y: pt1.y)
                        align = .right
                        labelPoint = CGPoint(x: pt2.x - 5, y: pt2.y - lineHeight)
                    }
                    else
                    {
                        
                        pt2 = CGPoint(x: center.x + radius * 1.5, y: pt1.y)
                        align = .left
                        labelPoint = CGPoint(x: pt2.x + 5, y: pt2.y - lineHeight)
                    }
                    
                    if dataSet.valueLineColor != nil
                    {
                        context.setStrokeColor(dataSet.valueLineColor!.cgColor)
                        context.setLineWidth(dataSet.valueLineWidth)
                        
                        context.move(to: CGPoint(x: pt0.x, y: pt0.y))
                        context.addLine(to: CGPoint(x: pt1.x, y: pt1.y))
                        context.addLine(to: CGPoint(x: pt2.x, y: pt2.y))
                        
                        context.drawPath(using: CGPathDrawingMode.stroke)
                        
                        context.setFillColor(dataSet.valueLineColor!.cgColor)
                        
                        // The hole rect
//                        rect.origin.x = pt2.x - 2
//                        rect.origin.y = pt2.y - 2
//                        rect.size.width = 4
//                        rect.size.height = 4
//
//                        context.fillEllipse(in: rect)
                        
                    }
                    
                    if drawXOutside && drawYOutside
                    {
                        context.drawText(valueText, at: labelPoint, align: align, attributes: [NSAttributedString.Key.font: valueFont, NSAttributedString.Key.foregroundColor: valueTextColor])
                        
                        if j < data.entryCount && pe?.label != nil
                        {
                          context.drawText(pe!.label!, at: CGPoint(x: labelPoint.x, y: labelPoint.y + lineHeight), align: align, attributes: [
                                    NSAttributedString.Key.font: entryLabelFont ?? valueFont,
                                    NSAttributedString.Key.foregroundColor: entryLabelColor ?? valueTextColor]
                            )
                        }
                    }
                    else if drawXOutside
                    {
                        if j < data.entryCount && pe?.label != nil
                        {
                          context.drawText(pe!.label!, at: CGPoint(x: labelPoint.x, y: labelPoint.y + lineHeight / 2.0), align: align, attributes: [
                                    NSAttributedString.Key.font: entryLabelFont ?? valueFont,
                                    NSAttributedString.Key.foregroundColor: entryLabelColor ?? valueTextColor]
                            )
                        }
                    }
                    else if drawYOutside
                    {
                        // 避免重合
                        var y = labelPoint.y + lineHeight / 2.0
                        if prePoint != CGPoint.zero {
                            prePoint.y += lineHeight/2
                            if (abs(y - prePoint.y) < lineHeight && abs(labelPoint.x - prePoint.x) < 10.0)
                            {
                                if labelPoint.x > center.x {
                                    y = prePoint.y+lineHeight/3.0
                                } else {
                                    y = prePoint.y - lineHeight
                                }
                                
                                labelPoint.x = prePoint.x
                            }
                        }
                        
                        y = y - 2
                        context.drawText(valueText, at: CGPoint(x: labelPoint.x, y: y), align: align, attributes: [NSAttributedString.Key.font: valueFont, NSAttributedString.Key.foregroundColor: valueTextColor])
                        
                        prePoint =  CGPoint(x: labelPoint.x, y: y)
                    }
                }
                
                if drawXInside || drawYInside
                {
                    // calculate the text position
                    let x = labelRadius * sliceXBase + center.x
                    let y = labelRadius * sliceYBase + center.y - lineHeight
                    
                    if drawXInside && drawYInside
                    {
                        context.drawText(valueText, at: CGPoint(x: x, y: y), align: .center, attributes: [NSAttributedString.Key.font: valueFont, NSAttributedString.Key.foregroundColor: valueTextColor])
                        
                        if j < data.entryCount && pe?.label != nil
                        {
                          context.drawText(pe!.label!, at: CGPoint(x: x, y: y + lineHeight), align: .center, attributes: [
                                    NSAttributedString.Key.font: entryLabelFont ?? valueFont,
                                    NSAttributedString.Key.foregroundColor: entryLabelColor ?? valueTextColor]
                            )
                        }
                    }
                    else if drawXInside
                    {
                        if j < data.entryCount && pe?.label != nil
                        {
                          context.drawText(pe!.label!, at: CGPoint(x: x, y: y + lineHeight / 2.0), align: .center, attributes: [
                                    NSAttributedString.Key.font: entryLabelFont ?? valueFont,
                                    NSAttributedString.Key.foregroundColor: entryLabelColor ?? valueTextColor]
                            )
                        }
                    }
                    else if drawYInside
                    {
                        context.drawText(valueText, at: CGPoint(x: x, y: y + lineHeight / 2.0), align: .center, attributes: [NSAttributedString.Key.font: valueFont, NSAttributedString.Key.foregroundColor: valueTextColor])
                    }
                }
                
                if let icon = e.icon, dataSet.isDrawIconsEnabled
                {
                    // calculate the icon's position
                    
                    let x = (labelRadius + iconsOffset.y) * sliceXBase + center.x
                    var y = (labelRadius + iconsOffset.y) * sliceYBase + center.y
                    y += iconsOffset.x
                    
                    context.drawImage(icon, atCenter: CGPoint(x: x, y: y), size: icon.size)
                }
                
                xIndex += 1
            }
        }
    }
    
}

